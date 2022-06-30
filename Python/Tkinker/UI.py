from tkinter import *
from tkinter import messagebox


class Application(Frame):


    def __init__(self, master=None):
        super().__init__(master)  # super代表父类的定义，不是父类对象

        self.master = master
        self.pack()
        self.CreateHomePage()

    def CreateHomePage(self):
        #创建并显示搜索标题
        self.HomeTitleFrame = Frame(self,height=50,width=600)
        self.HomeTitleFrame.pack()
        self.HomeTitleLable = Label(self.HomeTitleFrame, text='欢迎来到检索系统',font=("黑体", 25))
        self.HomeTitleLable.pack()

        #创建并显示搜索框
        global SearchText
        SearchText = StringVar()
        self.SearchFrame=Frame(self,width=800,height=300)
        self.SearchFrame.pack()
        self.SearchText=Entry(self.SearchFrame,textvariable=SearchText,width=100)

        self.SearchText.place(relx=0.2,rely=0.2,height=40,width=500)
        self.SearchButton=Button(self.SearchFrame,text='搜索',command=self.Search)
        self.SearchButton.place(width=80,height=40,x=700,rely=0.2)

    def HideHomePage(self):
        self.HomeTitleFrame.forget()
        self.HomeTitleLable.forget()
        self.SearchFrame.forget()
        self.SearchButton.forget()
        self.SearchButton.forget()

    def Search(self):
        self.HideHomePage()

if __name__ == '__main__':
    root = Tk()
    root.geometry("800x500")  # 窗口大小和窗口位置
    root.resizable(height=False,width=False)
    root.title("检索系统")
    app = Application(master=root)
    root.mainloop()
