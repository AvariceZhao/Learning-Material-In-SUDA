from tkinter import *
from tkinter import messagebox

root = Tk()
root.title("hello world")
root.geometry("500x300+100+200")
btn01 = Button(root)
btn01["text"] = '点我送花'
btn01.pack()


def songhua(e):
    messagebox.showinfo('Message', '送你一朵花')
    print('送你一朵话')


btn01.bind("<Button-1>", songhua)
root.mainloop()
