import threading

def sum(a):
    while(True):
        print('hello')
        
t = threading.Thread(target=sum, args=(100))
t.start()
