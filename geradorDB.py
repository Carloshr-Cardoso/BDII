from random import randint
import mysql.connector
from time import time
from threading import Thread

#CRIAÇÃO DO BANCO DE DADOS

##conn = mysql.connector.connect(user='root', password='caique140', host='localhost', database='cadastro')
##cur = conn.cursor()
##
##cur.execute("DROP DATABASE IF EXISTS teste")
##cur.execute("CREATE DATABASE teste")
##cur.execute("USE teste")
##cur.execute("""CREATE TABLE pessoa(
##                sexo integer,
##                idade integer,
##                renda integer,
##                escolaridade integer,
##                idioma integer,
##                pais integer,
##                locality integer
##            );""")
def generate():
    conn = mysql.connector.connect(user='root', password='caique140', host='localhost', database='teste')
    cur = conn.cursor()
    #166666667
    for i in range(40000000):
        sexo = randint(0,1)
        idade = randint(0,127)
        renda = randint(0,1023)
        escolaridade = randint(0,3)
        idioma = randint(0,4095)
        pais = randint(0,255)
        localidade = randint(0,16777215)
        cur.execute("INSERT INTO pessoa VALUES("+str(sexo)+", "+str(idade)+", "+str(renda)+", "+str(escolaridade)+", "+str(idioma)+", "+str(pais)+", "+str(localidade)+");")
        if i % 10000 == 0:
            conn.commit()

t0 = Thread(target=generate)
t1 = Thread(target=generate)
t2 = Thread(target=generate)
t3 = Thread(target=generate)
t4 = Thread(target=generate)
t5 = Thread(target=generate)
t6 = Thread(target=generate)
t7 = Thread(target=generate)
t8 = Thread(target=generate)
t9 = Thread(target=generate)

t0.start()
t1.start()
t2.start()
t3.start()
t4.start()
t5.start()
t6.start()
t7.start()
t8.start()
t9.start()


##conn.commit()

##tempoIni = time()
##cur.execute("SELECT * FROM pessoa;")
##for i in cur.fetchall():
##    print (i)
##tempoFim = time()
##tempoTot = tempoFim - tempoIni
##arq = open("executionTime.txt", 'w')
##arq.write(str(tempoTot))
