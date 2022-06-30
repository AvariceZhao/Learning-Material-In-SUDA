from tkinter import *
from tkinter import messagebox

class Application(Frame):
    def __init__(self,master=None):
        super().__init__(master)
        self.master=master
        self.pack()
        self.createWidget()

    def createWidget(self):
        self.lable1=Label(self,text='用户名')
        self.lable1.pack()
        global v1
        v1=StringVar()#讲变量绑定到组件内容
        self.entry01 = Entry(self,textvariable=v1)
        self.entry01.pack()
        v1.set('admin')
        print(v1.get())#get获取v1内容

        self.lable2 = Label(self, text='密码')
        self.lable2.pack()
        global v2
        v2 = StringVar()  # 讲变量绑定到组件内容
        self.entry02 = Entry(self, textvariable=v2,show='*')
        self.entry02.pack()
        v2.set('')

        self.btn01=Button(self,text='登录',command=self.login)
        self.btn01.pack()

    def login(self):
        username=v1.get()
        pwd=v2.get()
        if username=='admin'and pwd=='123':
            messagebox.showinfo('登录信息','登录成功')
        else:
            messagebox.showinfo('登录信息','登录失败')


if __name__=='__main__':
    root=Tk()
    root.geometry('400x130+200+300')
    app=Application(master=root)
    root.mainloop()