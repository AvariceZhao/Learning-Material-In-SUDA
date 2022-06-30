from tkinter import *
from tkinter import messagebox

root = Tk()
root.geometry("530x300")
c1 = Canvas(root, width=200, height=200, bg='green')
c1.pack()


def mouseTest(event):
    print('鼠标左键单机位置相对与父容器:{0},{1}'.format(event.x, event.y))
    print('鼠标左键单击位置相对于屏幕：'.format(event.x_root, event.y_root))
    print('时间绑定的组件:{0}'.format(event.widget))


def testDrag(event):
    c1.create_oval(event.x, event.y, event.x + 1, event.y + 1)


def testKeyboard(event):
    print('键的keycode{0},键的char{},键的keysym:{2}'.format(event.keycode, event.char, event.keysym))


def press_a(event):
    print('press a')


def release_a(event):
    print('release a')


c1.bind('<Button-1>', mouseTest)
c1.bind('B1-Motion', testDrag)
root.bind('<KeyPress>', testKeyboard)
root.bind('<KeyPress-a>', press_a)
root.bind("KeyRelease-a", release_a)
root.mainloop()
