from tkinter import *
from tkinter import messagebox
import os
from bs4 import BeautifulSoup
import re
from WebRank import *
import webbrowser


def openfile(event):
    FileName = event.widget.cget("text")
    try:
        path = os.path.abspath('') + '\\data\\' + FileName+'.txt'
        f = open(path)
        f.close()
        webbrowser.open(path)
    except BaseException:
        messagebox.showinfo('提示', '无法寻找到对应文件,文件打开失败\n请检查文件保存路径')


class Application(Frame):

    def __init__(self, master=None):
        super().__init__(master)  # super代表父类的定义，不是父类对象
        # 提前建立所需变量

        self.FrameState = None
        self.SearchButton = None
        self.SearchText = None
        self.SearchFrame = None
        self.HomeTitleLabel = None
        self.HomeTitleFrame = None
        self.btnQuit = None
        self.AnswerFrame = None
        self.PageLabel = None
        self.PageUpBtn = None
        self.PageDownBtn = None

        self.master = master
        self.pack()
        self.PageState = 1
        self.FrameList = []
        self.page = 1

        self.CreateHomePage()

    def CreateHomePage(self):  # 创建主页面

        # 创建退出按钮
        self.btnQuit = Button(root, text="退出", command=root.destroy, height=1, width=5, font=('黑体', 15), bg='red')
        self.btnQuit.place(x=900, y=10)

        # 创建并显示标题
        self.HomeTitleFrame = Frame(self, height=50, width=500)
        self.HomeTitleFrame.pack(pady=100)
        self.HomeTitleLabel = Label(self.HomeTitleFrame, text='欢迎来到本检索系统', font=("黑体", 40))
        self.HomeTitleLabel.pack()

        # 创建并显示搜索框
        global SearchContent
        SearchContent = StringVar()
        self.SearchFrame = Frame(self, width=750, height=50)
        self.SearchFrame.pack()
        self.SearchText = Entry(self.SearchFrame, textvariable=SearchContent, width=100, font=('宋体', 15))
        self.SearchText.place(relx=0.1, rely=0.2, height=40, width=500)

        # 创建搜索按钮
        self.SearchButton = Button(self.SearchFrame, text='搜索', font=('黑体', 15), command=self.Search)
        self.SearchButton.place(width=80, height=40, x=650, rely=0.2)

        #添加作者标签
        Label(root,text='by ZP',font=('黑体', 15)).place(relx=0.92,rely=0.95)

    def HideHomePage(self):
        # 隐藏主页显示搜索结果页
        self.HomeTitleFrame.forget()
        self.HomeTitleLabel.forget()
        self.SearchFrame.forget()
        self.SearchButton.forget()
        self.SearchText.forget()

    def Search(self):

        # 搜索
        global SearchAnswer
        SearchAnswer = []
        SearchAnswer = WebRankQuery(SearchContent.get())
        self.page = 1
        if not SearchAnswer:
            messagebox.showinfo('消息', '无法查询到相关文档')
        else:

            self.ShowSearchAnswer()

    # 上一页
    def pageup(self):

        if self.page > 1:
            # 删除原有的
            for i in range((self.page - 1) * 4, min(len(SearchAnswer), self.page * 4)):
                self.FrameList[i].forget()

            self.page -= 1
            # 放置新的
            root.update()
            Label(root, text='第{}页,共{}页'.format(self.page, maxpage), font=('黑体', 17)).place(relx=0.3, width=300,
                                                                                            rely=0.9, height=50)
            for i in range((self.page - 1) * 4, self.page * 4):
                if self.FrameState[i] == 1:
                    self.FrameList[i].pack(padx=10, pady=10)
                else:
                    self.FrameState[i] = 1
                    self.FrameList[i].pack(padx=10, pady=10)
                    label = Label(self.FrameList[i], height=2, width=200, text=SearchAnswer[i][0][0:-4], anchor='w',
                                  font=('黑体', 17),fg='blue')
                    label.bind('<Double-Button-1>', openfile)
                    label.pack()

                    text = Text(self.FrameList[i], height=3, width=500, font=('黑体', 15))

                    text.insert('insert', SearchAnswer[i][1])
                    text.config(state='disabled')
                    text.pack()

    # 下一页
    def pagedown(self):

        if self.page < maxpage:
            # 删除原有的
            for i in range((self.page - 1) * 4, min(len(SearchAnswer), self.page * 4)):
                self.FrameList[i].forget()
            self.page += 1
            Label(root, text='第{}页,共{}页'.format(self.page, maxpage), font=('黑体', 17)).place(relx=0.3, width=300,
                                                                                            rely=0.9, height=50)
            root.update()
            # 放置新的
            for i in range((self.page - 1) * 4, min(len(SearchAnswer), self.page * 4)):
                if self.FrameState[i] == 0:
                    self.FrameState[i] = 1
                    self.FrameList[i].pack(padx=10, pady=10)
                    label = Label(self.FrameList[i], height=2, width=200, text=SearchAnswer[i][0][0:-4], anchor='w',
                                  font=('黑体', 17),fg='blue')
                    label.bind('<Double-Button-1>', openfile)
                    label.pack()

                    text = Text(self.FrameList[i], height=3, width=500, font=('黑体', 15))

                    text.insert('insert', SearchAnswer[i][1])
                    text.config(state='disabled')
                    text.pack()
                else:
                    self.FrameList[i].pack(padx=10, pady=10)

    def ShowSearchAnswer(self):

        # 展示第一页的搜索结果

        for i in self.FrameList:  # 销毁上一次搜索结果
            i.destroy()

        # 隐藏原页面
        self.HideHomePage()

        # 创建新页面

        # 顶部搜索栏
        self.SearchFrame.pack()
        self.SearchText.place(relx=0.01, rely=0.01, height=40, width=500)
        self.SearchButton.place(width=80, height=40, x=540, rely=0.01)

        # 底部翻页按钮
        global maxpage
        maxpage = math.ceil(len(SearchAnswer) / 4)

        # 放置底部按钮和页数标签
        self.PageUpBtn = Button(root, text='上一页', command=self.pageup)
        self.PageDownBtn = Button(root, text='下一页', command=self.pagedown)
        self.PageLabel = Label(root, text='第{}页,共{}页'.format(self.page, maxpage), font=('黑体', 17))
        self.PageUpBtn.place(relx=0.1, rely=0.9, width=100, height=50)
        self.PageDownBtn.place(relx=0.8, rely=0.9, width=100, height=50)
        self.PageLabel.place(relx=0.3, width=300, rely=0.9, height=50)

        # 创建搜索结果显示框架
        self.FrameList = [Frame(root, width=500, height=80) for i in range(len(SearchAnswer))]
        self.FrameState = [0 for i in range(len(SearchAnswer))]

        #显示搜索结果
        for i in range(min(4, len(SearchAnswer))):
            self.FrameList[i].pack(padx=100, pady=10)
            self.FrameState[i] = 1

            label = Label(self.FrameList[i], height=2, width=200, text=SearchAnswer[i][0][0:-4], anchor='w',
                          font=('黑体', 17),fg='blue')
            label.bind('<Double-Button-1>', openfile)

            label.pack()

            text = Text(self.FrameList[i], height=3, width=500, font=('黑体', 15))
            text.insert('insert', SearchAnswer[i][1])

            text.config(state='disabled')
            text.pack()


if __name__ == '__main__':
    root = Tk()

    SearchText = StringVar()
    root.geometry("1000x700+200+200")  # 窗口大小和窗口位置
    root.resizable(height=False, width=False)
    root.title("检索系统")
    app = Application(master=root)
    messagebox.showinfo('提示', '开始初始化,需等待5-6秒左右')

    init()

    messagebox.showinfo('提示', '初始化完成')
    messagebox.showinfo('使用说明',
                        '1.在搜索栏内输入完整语句或者输入自定义分词的语句\n'
                        '2.点击右侧搜索按钮将显示搜索结果\n'
                        '3.如果搜索不到文档则会弹窗提示\n'
                        '4.点击搜索结果的标题可以打开对应的文本文件')
    root.mainloop()
