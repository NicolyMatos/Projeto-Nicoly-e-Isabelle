import json

from flask import Flask, render_template, redirect, request
from flask_socketio import SocketIO, send, emit
from flask_cors import CORS

app = Flask(__name__)
socketio = SocketIO(app)
CORS(app)

estado = {
    "ALARME" : 0,
    "SENSOR" : 0
}


@app.route("/")
def rota_inicial():
    return render_template("index.html")
    
@app.route("/upload",methods =["POST"])
def rota_upload():
    mensagem =request.get_json()
    socketio.emit("atualiza",mensagem)
    return "200"


@app.route("/download", methods=['GET'])
def rota_download():
    global estado
    return json.dumps(estado)

@socketio.on("ativarAlarme")
def ativar_alarme():
    global estado
    estado["ALARME"]=1

@socketio.on("desativarAlarme")
def desligar_alarme():
    global estado
    estado["ALARME"]=0

@app.route("/dados", methods=['GET'])
def rota_dados():
    global valor
    return json.dumps(valor)

@socketio.on("atualizarValor")
def atualizar_Valor():
    global valor 
    valor=request.get_json()
    socketio.emit("valor",valor)



if __name__ == "__main__":
    app.run("0.0.0.0",port=8080)