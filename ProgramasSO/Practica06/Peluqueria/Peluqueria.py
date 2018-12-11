#Importas librerias necesarias.
from threading import Thread, Lock, Event
import time, random

mutex = Lock()

#Introduces valores de tiempo de intervalos
customerIntervalMin = 5
customerIntervalMax = 15
haircutDurationMin = 3
haircutDurationMax = 15

# Defines la clase barberia que atendera a los clientes.
class BarberShop:
	waitingCustomers = []

	# en esta parte imprimimos los valores antes inicializados
	def __init__(self, barber, numberOfSeats):
		self.barber = barber
		self.numberOfSeats = numberOfSeats
		print 'Barberia inicializada con  {0} asientos'.format(numberOfSeats)
		print 'Cliente  intervalo minimo de tiempo {0}'.format(customerIntervalMin)
		print 'Cliente intervalo maximo de tiempo {0}'.format(customerIntervalMax)
		print 'Corte de cabello intervalo minimo {0}'.format(haircutDurationMin)
		print 'Corte de cabello intervalo minimo {0}'.format(customerIntervalMax)
		print '---------------------------------------'
#Metodo que te dice si esta abierta o no la tienda
	def openShop(self):
		print 'Barberia esta abierta'
		workingThread = Thread(target = self.barberGoToWork)
		workingThread.start()
#Metodo que te dice si el barbero esta disponible.
	def barberGoToWork(self):
		while True:
			mutex.acquire()

			if len(self.waitingCustomers) > 0:
				c = self.waitingCustomers[0]
				del self.waitingCustomers[0]
				mutex.release()
				self.barber.cutHair(c)
			else:
				mutex.release()
				print 'Todo terminado, ve a dormir'
				barber.sleep()
				print 'Barbero despierta'
# Metodo que dice si el barbero esta o no en la tienda.
	def enterBarberShop(self, customer):
		mutex.acquire()
		print '>> {0} entrando a la tienda y buscando asiento'.format(customer.name)

		if len(self.waitingCustomers) == self.numberOfSeats:
			print 'Esperando cuarto lleno, {0} esta disponible.'.format(customer.name)
			mutex.release()
		else:
			print '{0} se sento en el cuarto de espera'.format(customer.name)
			self.waitingCustomers.append(c)
			mutex.release()
			barber.wakeUp()


class Customer:
	def __init__(self, name):
		self.name = name
#Clase que modela un barbero y todas sus funciones
class Barber:
	barberWorkingEvent = Event()

	def sleep(self):
		self.barberWorkingEvent.wait()

	def wakeUp(self):
		self.barberWorkingEvent.set()

	def cutHair(self, customer):
		#Set barber as busy
		self.barberWorkingEvent.clear()

		print '{0} Esta teniendo un corte de cabello'.format(customer.name)

		randomHairCuttingTime = random.randrange(haircutDurationMin, haircutDurationMax+1)
		time.sleep(randomHairCuttingTime)
		print '{0} esta hecho'.format(customer.name)


if __name__ == '__main__':
	#Inicialiazas a clientes que entran a la tienda
	customers = []
	customers.append(Customer('Gibran'))
	customers.append(Customer('Alexis'))
	customers.append(Customer('Dani'))
	customers.append(Customer('Fernando'))
	#Creas un barbero
	barber = Barber()

	barberShop = BarberShop(barber, numberOfSeats=3)
	barberShop.openShop()

	while len(customers) > 0:
		c = customers.pop()
		#Nuevo cliente entra a la tienda
		barberShop.enterBarberShop(c)
		customerInterval = random.randrange(customerIntervalMin,customerIntervalMax+1)
		time.sleep(customerInterval)
