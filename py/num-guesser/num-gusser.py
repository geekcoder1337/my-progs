from tkinter import *
from tkinter import messagebox
from time import sleep
from threading import Thread
import random

num = 0

def startup():
    lbl.config(text='Welcome to\nnumber guesser!')
    sleep(2)
    lbl.config(text='This game is TEST\nof Python GUI!')
    sleep(2)
    new_game()

def new_game():
    global num
    num = random.randint(0,100)
    lbl.pack()
    ent.pack()
    btn.pack()
    lbl.config(text='Guess the number!')

def answerChecker():
    global num
    try:
        btn['state']='disabled'
        val = int(ent.get())
        if num!=val:
            messagebox.showerror('Oops...','FAIL! Try again!')
            if num>val:
                messagebox.showinfo('INFO','Number is higher!')
            elif num<val:
                messagebox.showinfo('INFO','Number is lower!')
            btn['state']='normal'
        else:
            messagebox.showinfo('Congrat!!!','Number guessed!\nYou win!')
            if messagebox.askyesno('Question','Continue the game?'):
                btn['state']='normal'
                new_game()
            else:
                messagebox.showwarning('Warning!','Game will closed now!')
                root.destroy()
    except:
        btn['state']='normal'
        messagebox.showerror('Error','Type NUMBER!')

root = Tk()
root.title('Number guesser!')
root.geometry('700x500')

lbl = Label(font=('Arial',30))
ent = Entry(width=10)
btn = Button(text='Check the answer!',command=answerChecker)

lbl.pack()
th = Thread(target=startup)
th.start()

root.mainloop()