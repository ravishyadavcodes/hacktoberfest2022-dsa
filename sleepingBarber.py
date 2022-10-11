from threading import Thread, Lock, Event
import time, random

mutex = Lock()

#Interval in seconds
#you can modify the values to force a starvation situation
#with customers arriving in short time or sighted
clienteIntervaloMin = 5
clienteIntervaloMax = 15
corteDuracaoMin = 3
corteDuracaoMax = 15
totalAssentos = 5

class Barbearia:
    clientesEsperando = []

    def __init__(self, barbeiro, numeroDeAssentos):
        self.barbeiro = barbeiro
        self.numeroDeAssentos = numeroDeAssentos
        print ('Barbearia iniciada com {0} assentos'.format(numeroDeAssentos))
        print ('Cliente intervalo minimo {0}'.format(clienteIntervaloMin))
        print ('Cliente intervalo maximo {0}'.format(clienteIntervaloMax))
        print ('Duracao minima de corte {0}'.format(corteDuracaoMin))
        print ('Duracao maxima de corte {0}'.format(corteDuracaoMax))
        print ('---------------------------------------')

    def abrirBarbearia(self):
        print('A barbearia esta aberta')
        workingThread = Thread(target = self.barbeiroVaiTrabalhar)
        workingThread.start() #start the thread that will take care of the barber traffic lights and waiting customers

    def barbeiroVaiTrabalhar(self):
        while True:
            mutex.acquire()

            if len(self.clientesEsperando) > 0:
                c = self.clientesEsperando[0]
                del self.clientesEsperando[0]
                mutex.release()
                self.barbeiro.cortaCabelo(c)
            else:
                mutex.release()
                print("Aaah, tudo feito, hora de dormir")
                barbeiro.dormir()
                print('Barbeiro, acorde!')

    def entraNaBarbearia(self, cliente):
        mutex.acquire()
        print ('>> {0} entrou na barbearia e esta procurando por um assento'.format(cliente.name))

        if len(self.clientesEsperando) == self.numeroDeAssentos:
            print('A sala de espera esta cheia, {0} esta saindo.'.format(cliente.name))
            mutex.release()
        else:
            print ('{0} sentou-se na sala de espera'.format(cliente.name))	
            self.clientesEsperando.append(c)	
            mutex.release()
            barbeiro.acordar()


class Cliente:
    def __init__(self, name):
        self.name = name


class Barbeiro:
    eventoBarbeiroTrabalhando = Event()

    def dormir(self):
        self.eventoBarbeiroTrabalhando.wait()
    
    def acordar(self):
        self.eventoBarbeiroTrabalhando.set()

    def cortaCabelo(self, cliente):
        self.eventoBarbeiroTrabalhando.clear()

        print ('{0} esta recebendo um corte de cabelo'.format(cliente.name))

        tempoDeCorteAleatorio = random.randrange(corteDuracaoMin, corteDuracaoMax+1)
        time.sleep(tempoDeCorteAleatorio)
        print ('{0} esta pronto'.format(cliente.name))

if __name__ == '__main__':
	cliente = []
	cliente.append(Cliente('Rafael'))
	cliente.append(Cliente('Lucas'))
	cliente.append(Cliente('Gustavo'))
	cliente.append(Cliente('Alex'))
	cliente.append(Cliente('Andre'))
	cliente.append(Cliente('Luis'))
	cliente.append(Cliente('Vinicius'))
	cliente.append(Cliente('Rohan'))
	cliente.append(Cliente('Manoel'))
	cliente.append(Cliente('Marcos'))
	cliente.append(Cliente('Jose'))
	cliente.append(Cliente('George'))
	cliente.append(Cliente('Enzo'))
	cliente.append(Cliente('Ben'))
	cliente.append(Cliente('Splinter'))
	cliente.append(Cliente('Leonardo'))
	cliente.append(Cliente('Michelangelo'))

barbeiro = Barbeiro()
                                
barbearia = Barbearia(barbeiro, numeroDeAssentos=totalAssentos)
barbearia.abrirBarbearia()

while len(cliente) > 0:
    c = cliente.pop()
    barbearia.entraNaBarbearia(c)
    clienteIntervalo = random.randrange(clienteIntervaloMin, clienteIntervaloMax+1)
    time.sleep(clienteIntervalo)