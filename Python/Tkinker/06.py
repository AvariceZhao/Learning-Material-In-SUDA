from tkinter import *
import webbrowser


class Application(Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.master = master
        self.pack()
        self.createWidget()

    def createWidget(self):
        self.w1 = Text(root, width=40, height=12, bg='gray')
        self.w1.pack()

        self.w1.insert(1.0, "0123456789\nabcdefg")  # 在第一行第零列
        self.w1.insert(2.3, "锄禾日当午，汗滴禾下土，谁之盘中餐，粒粒皆辛苦\n")

        Button(self, text="重复插入文本", command=self.insertText).pack(side="left")
        Button(self, text="返回文本", command=self.returnText).pack(side="left")
        Button(self, text="添加图片", command=self.addImage).pack(side="left")
        Button(self, text="添加组件", command=self.addWidget).pack(side="left")
        Button(self, text="通过tag精确控制文本", command=self.testTag).pack(side="left")

    def insertText(self):
        # INSERT在光标处插入
        self.w1.insert(INSERT, 'ZP')
        # END在最后插入字符串
        self.w1.insert(END, '[zp]')

    def returnText(self):
        print(self.w1.get(1.2, 1.6))  # 第1行第2-6列
        self.w1.insert(1.8, 'zzpp')
        print('所有文本内容:\n' + self.w1.get(1.0, END))

    def addImage(self):
        self.photo = PhotoImage(file='./01.gif')
        self.w1.image_create(END, image=self.photo)

    def addWidget(self):
        b1 = Button(self.w1, text='fwzp')
        self.w1.window_create(INSERT, window=b1)

    def testTag(self):
        self.w1.delete(1.0, END)

        self.w1.delete(1.0, END)

        self.w1.tag_add('good',1.0,1.9)
        self.w1.tag_config("good",background='yellow',foreground='red')
        self.w1.tag_add('baidu',4.0,4.2)
        self.w1.tag_config("baidu",underline=True)
        self.w1.tag_bind("baidu","<Button-1>",self.webshow)
    def webshow(self,event):
        webbrowser.open("http://www.baidu.com")
if __name__ == '__main__':
    root = Tk()
    root.geometry('400x130+200+300')
    app = Application(master=root)
    root.mainloop()
