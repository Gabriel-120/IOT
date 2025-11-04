# Importações
from flask import Flask, render_template, jsonify
import serial
import time

# Configuração da porta serial do Arduino
try:
    arduino = serial.Serial('COM3', 9600, timeout=1)
    time.sleep(2)  # tempo para estabilizar
except serial.SerialException as e:
    print(f"Erro ao conectar com o Arduino: {e}")
    arduino = None

app = Flask(__name__)

# Rota principal que renderiza a página HTML
@app.route('/')
def index():
    return render_template('index.html')

# Rota que recebe comandos do HTML e envia ao Arduino
@app.route('/control/<led_num>/<action>')
def control(led_num, action):
    if arduino:
        command = ''
        if led_num == '1':
            command = 'A' if action == 'on' else 'a'
        elif led_num == '2':
            command = 'B' if action == 'on' else 'b'
        
        if command:
            arduino.write(command.encode())
            return f"Comando '{command}' enviado para o LED {led_num}."
        else:
            return "Comando inválido."
    else:
        return "Arduino não conectado."

# Rota para obter dados do sensor
@app.route('/get_data')
def get_data():
    if arduino:
        try:
            linha = arduino.readline().decode('utf-8').strip()
            temperatura = float(linha)
            umidade = '--'  # Pode ser adaptado se quiser receber umidade também
            return jsonify({"temperatura": temperatura, "umidade": umidade})
        except Exception as e:
            return jsonify({"error": str(e)})
    else:
        return jsonify({"error": "Arduino não conectado"})

# Execução do app Flask
if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000, use_reloader=False)
