# Importações
from flask import Flask, render_template, jsonify
import serial
import serial.tools.list_ports
import time

def find_arduino_port():
    """Encontra a porta do Arduino automaticamente"""
    ports = list(serial.tools.list_ports.comports())
    for port in ports:
        if "Arduino" in port.description or "CH340" in port.description:
            return port.device
    return None

# Configuração da porta serial do Arduino
arduino = None
try:
    port = find_arduino_port() or 'COM4'  # Tenta encontrar automaticamente ou usa COM3
    arduino = serial.Serial(port, 9600, timeout=1)
    time.sleep(2)  # tempo para estabilizar
    
    # Testa a conexão
    arduino.write(b'T')  # Envia comando de teste
    time.sleep(0.5)
    response = arduino.readline().decode().strip()
    if not response:
        print("Arduino não respondeu ao teste")
        arduino = None
except Exception as e:
    print(f"Erro ao conectar com o Arduino: {e}")
    arduino = None

app = Flask(__name__)

# Rota principal que renderiza a página HTML
@app.route('/')
def index():
    return render_template('index.html')

# Rota para verificar status da conexão
@app.route('/status')
def status():
    if arduino and arduino.is_open:
        try:
            arduino.write(b'T')  # Envia comando de teste
            time.sleep(0.5)
            response = arduino.readline().decode().strip()
            if response:
                return jsonify({"status": "connected"})
        except:
            pass
    return jsonify({"status": "disconnected"})

# Rota que recebe comandos do HTML e envia ao Arduino
@app.route('/control/<led_num>/<action>')
def control(led_num, action):
    if not arduino or not arduino.is_open:
        return jsonify({"error": "Arduino não conectado"}), 503
        
    try:
        command = ''
        if led_num == '1':
            command = 'A' if action == 'on' else 'a'
        elif led_num == '2':
            command = 'B' if action == 'on' else 'b'
            
        if command:
            arduino.write(command.encode())
            arduino.flush()  # Garante que o comando foi enviado
            time.sleep(0.1)  # Pequena pausa para processamento
            
            # Lê a resposta do Arduino
            response = arduino.readline().decode().strip()
            if response:
                return jsonify({"message": response})
            return jsonify({"message": f"Comando '{command}' enviado para o LED {led_num}."})
        else:
            return jsonify({"error": "Comando inválido"}), 400
    except Exception as e:
        return jsonify({"error": f"Erro ao controlar LED: {str(e)}"}), 500

# Execução do app Flask
if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000, use_reloader=False)
