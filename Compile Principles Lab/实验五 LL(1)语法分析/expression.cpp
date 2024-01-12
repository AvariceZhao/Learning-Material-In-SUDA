#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <fstream>
#include <sstream>
using namespace std;
//#define epsilon "epsilon"
#define epsilon "ε"
class GrammarItem 
{
public:
    string name;
    bool isTerminal;
    int id; 
    string value;
    int col, row;

    GrammarItem()
	{
		name = "";
		isTerminal = 0;
		id = 0;
	}
    GrammarItem(string name, bool isTerminal)
    {
        this->name = name;
        this->isTerminal = isTerminal;
        id = 0;
    }
    GrammarItem(string name, bool isTerminal, int id)
    {
        this->name = name;
        this->isTerminal = isTerminal;
        this->id = id;
    }
    bool operator<(const GrammarItem& item) const
    {

        return this->name < item.name;
    }
    friend istream &operator>>(istream &in, GrammarItem &item)
	{
		in >> item.name>>item.value>>item.row>>item.col;
        item.isTerminal = 1;
		return in;
	}
};
map<GrammarItem, vector<vector<GrammarItem>>> grammar
{
    {GrammarItem("E", false), {{GrammarItem("T", false), GrammarItem("E'", false)}}},
    {GrammarItem("E'", false), {{GrammarItem("+", true), GrammarItem("T", false), GrammarItem("E'", false)}, {GrammarItem(epsilon, true)}}},
    {GrammarItem("T", false), {{GrammarItem("F", false), GrammarItem("T'", false)}}},
    {GrammarItem("T'", false), {{GrammarItem("*", true), GrammarItem("F", false), GrammarItem("T'", false)}, {GrammarItem(epsilon, true)}}},
    {GrammarItem("F", false), {{GrammarItem("(", true), GrammarItem("E", false), GrammarItem(")", true)}, {GrammarItem("id", true)}}}
};
map<GrammarItem, set<GrammarItem>> first, follow;
map<GrammarItem, map<GrammarItem, vector<vector<GrammarItem>>>> table;
ifstream IN;
void calcFirst()
{

    for (auto& [item, products] : grammar)
    {
        for (auto product : products)
        {
            for (auto gram : product)
            {
                if (gram.isTerminal)
                {
                    first[item].insert(gram);
                    break;
                }
            }
        }
    }

    bool update = true;
    while (update)
    {
        update = false;
        for (auto& [item, products] : grammar)
        {
            for (auto product : products)
            {
                bool empty = true;
                for (auto gram : product)
                {
                    if (first[gram].find(GrammarItem(epsilon, true)) == first[gram].end())
                    {
                        empty = false;
                    }

                    if (!gram.isTerminal)
                    {
                        for (auto& i : first[gram])
                        {
                            if (i.name != epsilon && first[item].find(i) == first[item].end())
                            {
                                first[item].insert(i);
                         //       cout << item.name << " insert " << i.name << endl;

                                update = true;
                            }
                        }
                        if (!empty)
                        {
                            break;
                        }
                    }
                    else // 遇到终结符
                    {
                        if (gram.name != epsilon && first[item].find(gram) == first[item].end())
                        {
                            first[item].insert(gram);
                         //   cout << item.name << " insert " << gram.name << endl;
                            update = true;
                        }
                        if (gram.name != epsilon)
                        {
                            break;
                        }
                    }
                }
                if (empty)
                {
                    if (first[item].find(GrammarItem(epsilon, true)) == first[item].end())
                    {
                        first[item].insert(GrammarItem(epsilon, true));
                        update = true;
                    }
                }
            }
        }
    }
    /*
    cout << "-------------------First:-----------------------" << endl;
    for (auto& item : first)
    {
        cout << item.first.name << ": ";
        for (auto& i : item.second)
        {
            cout << i.name << " ";
        }
        cout << endl;
    }
    cout << "-------------------First:-----------------------" << endl;
    */
}

void calcFollow()
{
    follow[GrammarItem("E", false)].insert(GrammarItem("$", true));
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (auto& [item, products] : grammar) // 枚举每个非终结符
        {
            for (auto product : products) // 枚举每个产生式
            {
                for (int i = 0; i < product.size(); i++) // 枚举产生式里的每一位
                {
                    if (!product[i].isTerminal) // 如果是非终结符
                    {
                        for (int j = i + 1; j < product.size(); j++) // 枚举后面的每一位
                        {
                            if (product[j].isTerminal) // 如果是终结符
                            {
                                if (follow[product[i]].find(product[j]) == follow[product[i]].end()) // 如果没有在follow集合里，插入
                                {
                                    follow[product[i]].insert(product[j]);
                                    //   cout << item.name << " " << i << " " << j << " " << product[i].name << " insert " << product[j].name << endl;
                                    flag = true;
                                }
                                break;
                            }
                            else // 如果是非终结符
                            {
                                for (auto& k : first[product[j]]) // 遍历这个非终结符的first
                                {
                                    if (k.name != epsilon && follow[product[i]].find(k) == follow[product[i]].end())
                                    {
                                        follow[product[i]].insert(k);
                                        //    cout << item.name << " " << i << " " << j << " " << product[i].name << " insert " << k.name << endl;
                                        flag = true;
                                    }
                                }
                                if (first[product[j]].find(GrammarItem(epsilon, true)) == first[product[j]].end()) // 如果这个非终结符的first里没有空
                                {
                                    break;
                                }
                            }
                        }
                        if (i == product.size() - 1)
                        {
                            for (auto& k : follow[item])
                            {
                                if (follow[product[i]].find(k) == follow[product[i]].end())
                                {
                                    follow[product[i]].insert(k);
                                    // cout << item.name << " " << i << " "
                                    //      << " " << product[i].name << " insert " << k.name << endl;
                                    flag = true;
                                }
                            }
                        }
                        //     //如果存在 A->αB 或 A->αBβ 且 FIRST(β) 包含 ε，则 FOLLOW(A) 中的所有符号都在 FOLLOW(B) 中。

                        // if(item.name=="E'"&&product[0].name=="+"&&i==1)
                        // {
                        //     cout << "debug!:\n";

                        for (int j = product.size() - 1; j > i; j--)
                        {

                            if (!first[product[j]].count(GrammarItem(epsilon, true)))
                            {
                                break;
                            }
                            else
                            {
                                for (auto& k : follow[item])
                                {

                                    if (follow[product[i]].find(k) == follow[product[i]].end())
                                    {
                                        follow[product[i]].insert(k);
                                        //    cout << product[i].name << " insert " << k.name << endl;
                                        flag = true;
                                    }
                                }
                            }
                        }
                        // }
                    }
                }
            }
        }
    }
    /*
    cout << "-------------------Follow:-----------------------" << endl;
    for (auto& item : follow)
    {
        cout << item.first.name << ": ";
        for (auto& i : item.second)
        {
            cout << i.name << " ";
        }
        cout << endl;
    }
    cout << "-------------------Follow:-----------------------" << endl;
    */
}

void calcTable2()
{
    for (auto& [item, products] : grammar) // 遍历每个非终结符
    {
        for (auto& product : products) // 遍历非终结符的每个产生式
        {
            bool flag = 1;
            for (int i = 0; i < product.size(); i++)
            {
                if (product[i].name == epsilon)
                    continue;

                if (product[i].isTerminal && product[i].name != epsilon)
                {
                    table[item][product[i]].push_back(product);
                    flag = 0;
                    break;
                }
                else
                {

                    for (auto& j : first[product[i]])
                    {
                        if (j.name != epsilon)
                        {
                            table[item][j].push_back(product);
                        }
                    }
                    // 非终结符推不出空
                    if (first[product[i]].find(GrammarItem(epsilon, true)) == first[product[i]].end())
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag)
            {
                for (auto ch : follow[item])
                {
                    table[item][ch].push_back(product);
                }
                if (follow[item].find(GrammarItem("$", true)) == follow[item].end())
                {
                    {
                        table[item][GrammarItem("$", true)].push_back(product);
                    }
                }
            }
        }
    }

    /*
    cout << "-------------------Table:-----------------------" << endl;
    // map<GrammarItem, map<GrammarItem, vector<GrammarItem>>> table;
    for (auto [item, mp] : table)
    {
        cout << item.name << ":\n";
        for (auto [ch, products] : mp)
        {
            for (auto product : products)
            {
                cout << ch.name << "->";
                for (auto gram : product)
                {
                    cout << gram.name << " ";
                }
                cout << "###";
            }
            cout << endl;
        }

        cout << endl;
    }
    */
}
vector<GrammarItem> handleError(vector<vector<GrammarItem>> products, GrammarItem input1, GrammarItem stk_top)
{

    auto addr = IN.tellg();
  //  string str;
    //IN >> str;
    GrammarItem input2;
    IN >> input2;
   IN.seekg(addr);
    vector<GrammarItem> ans = { GrammarItem("error", true) };
    int satisfy = 0;

#ifdef DEBUG



     cout << "!!!!!\n";
     for (auto i : products)
     {
         cout << stk_top.name << "->";
         for (auto j : i)
         {
             cout << j.name << " ";
         }
         cout << endl;
     }
     cout << "input1:" << input1.name << " input2:" << input2.name <<" stk_top:"<<stk_top.name<<" " << endl;
     cout << "!!!!!\n";
#endif // DEBUG
    for (auto product : products)
    {
#ifdef DEBUG
        cout<<"product:";
        for (auto temp : product)
        {
            			cout<<temp.name<<" ";

        }
        cout << endl;
#endif // DEBUG
        bool flag = 1;
        auto item0 = product[0];
        if (item0.isTerminal) // 是终结符，必定等于input1
        {
            // if(product.size()<2)
            // {

            // }
            auto item1 = product[1];
            if (!item1.isTerminal)
            {
                if (first[item1].find(input2) == first[item1].end())
                {
                    flag = 0;
                }
                else
                {
                    ans = product;
                    satisfy++;
                }
            }
            else
            
            {
              
                if (item1.name != input2.name)
                {
                    flag = 0;
                }
                else
                {
                    ans = product;
                    satisfy++;
                }
            }
        }
        else // 非终结符，stk_top肯定在其first内
        {
            int matchCount = 0;
            bool error = 0;
            stack<GrammarItem> praseStack;
            praseStack.push(GrammarItem("$", true));
            for(int i=product.size()-1;i>=0;i--)
			{
				praseStack.push(product[i]);
			}
       


            GrammarItem X("error",true);
            if (product.size() >= 2)
				X = product[1];
			else
				X = product[0];
            auto a = input1;
            while (matchCount != 2&&X.name!="$")
            {
                #ifdef DEBUG
                cout << "----------------------------\n";
                auto stk2 = praseStack;
                cout << "current stack:";
                while (!stk2.empty())
                {
                    cout << stk2.top().name << " ";
                    stk2.pop();
                }
                cout << endl;
                cout << "current input:" << a.name << endl;
                cout << "current X:" << X.name << endl;
                cout << "----------------------------\n";
                cout<<"error:"<<error<<endl;
                #endif
                if (error)
                {
                    break;
                }
                if (X.isTerminal)
                {    
                  //    cout<<"X terminal:"<<X.name<<":"<<a.name<<"matchcount:" <<matchCount<<"X.name == a.name" << (X.name == a.name)<<endl;
                    if (X.name == a.name)
                    {
                        matchCount++;
                        if (matchCount == 2)
                        {
                            ans = product;
                            break;
                        }
                  //      cout << "pop1:" << praseStack.size() << endl;
                        praseStack.pop();
                        a = input2;
                    }
                    else
                    {
                        error = 1;
                        break;
                    }
                }
                else
                {
                    if (table[X].find(a) != table[X].end())
                    {
                //        cout << "pop2:" << praseStack.size() << endl;
                        praseStack.pop();
                        vector<vector<GrammarItem>> tempProducts = table[X][a];
                        vector<GrammarItem> tempProduct = tempProducts[0];
                  /*      cout << "choose:";
                        for (auto jjj : tempProduct)
                        {
                            cout << jjj.name << " ";
                        }
                        cout << endl;*/
                        if (tempProducts.size() > 1)
                        {
                          
                       //    cout << "222222\n";
                            error = 1;
                            break;
                        }

                        if (tempProduct[0].name == epsilon)
                        {
                        //    cout<<"siz:" << praseStack.size() << endl;
                            X = praseStack.top();
                            continue;
                        }
                        for (int i = tempProduct.size() - 1; i >= 0; i--)
                        {
                            praseStack.push(tempProduct[i]);
                        }
                    }
                    else
                    {
                      //  cout << "3333333\n";
                        error = 1;
                        break;
                    }
                }
                
                X = praseStack.top();
            }
            if (!error)
            {
				ans = product;
				satisfy++;
			}
        }
    }
#ifdef DEBUG



    cout << "handleError:" << stk_top.name << "->";
    for (auto i : ans)
    {
        cout << i.name << " ";
    }
    cout << endl;
    cout<<"satisfy:"<<satisfy<<endl;
#endif // DEBUG
    if (satisfy == 0 || satisfy >= 2)
        return vector<GrammarItem>{GrammarItem("error", true)};
    else
        return ans;
}
void draw(vector<vector<GrammarItem>> result)
{
    cout << "-------------------draw:-----------------------" << endl;

    // 在点的字符串里添加的空格数
    vector<string> drawFile;
    drawFile.push_back("digraph G {");
    drawFile.push_back("graph [ratio = 1];");
    for (auto production : result)
    {
        auto head = production[0].name;
        string s;
        stringstream ss(s);
        ss << production[0].id;
        head = head + "_" + ss.str();

        drawFile.push_back("\"" + head + "\"[label=\"" + production[0].name + "\"];");
        //   cnt[production[0]]++;

        for (int i = 1; i < production.size(); i++)
        {
            string str = production[i].name;
            string s;
            stringstream ss(s);
            ss << production[i].id;
            str = str + "_" + ss.str();
            drawFile.push_back("\"" + str + "\"[label=\"" + production[i].name + "\"];");
            drawFile.push_back("\"" + head + "\"" + "->" + "\"" + str + "\";");
            //if (production[i].isTerminal)
            //{
            //    drawFile.push_back("\"" + head + "\"" + "->" + "\"" + production[i].value + "\";");
            //}
            // if(!production[i].isTerminal)
            //      continue;
        }
    }
    drawFile.push_back("}");
    ofstream out("draw.dot");
    for (auto str : drawFile)
    {
        out << str << endl;
    }
    out.close();
    system("dot -Tpng draw.dot -o draw.png");
}

int predictPrase()
{
    vector<vector<GrammarItem>> result;
    vector<GrammarItem> currentProduction =  {GrammarItem("{", true), GrammarItem("declaration_list", false), GrammarItem("statement_list", false), GrammarItem("}", true)} ;
    GrammarItem currentNoneTerminal = GrammarItem("E", false);
    stack<GrammarItem> stk;
    map<string, int> cnt;
    stk.push(GrammarItem("$", true, cnt["$"]++));
    stk.push(GrammarItem("program", false, cnt["program"]++));
    
    //string str;
    //IN >> str;
    GrammarItem X = stk.top();
    GrammarItem a = GrammarItem();
    IN >> a;
    
    while (X.name != "$")
    {

#ifdef DEBUG



        cout << "*****************\n";
        auto stk2 = stk;
        cout << "current stack:";
        while (!stk2.empty())
        {
            cout << stk2.top().name << " ";
            stk2.pop();
        }
        cout << endl;
        cout << "current input:" << a.name << endl;
        cout << "current X:" << X.name << endl;
        cout << "*****************\n";
#endif // DEBUG
        if (X.isTerminal)
        {
            if (X.name == a.name)
            {

                cout << "match " << a.name << endl;

                stk.pop();
                IN >> a;
            }
            else
            {
               
                cout << a.row << ":" << a.col << ":" << "Error in " << currentNoneTerminal.name << endl;
              /*  cout << "using Production:";
                for (auto gram : currentProduction)
				{
					cout << gram.name << " ";
				}
                cout << endl;*/
                cout<<"Expected:"<<X.name<<" "<<"but get:"<<a.name<<endl;
                return 1;
            }
        }
        else
        {
            if (table[X].find(a) != table[X].end())
            {
                stk.pop();
                vector<vector<GrammarItem>> products = table[X][a];
                vector<GrammarItem> product = products[0];
              
                if (products.size() > 1)
                {
              //      product = handleError(products, a, X);
                    auto tempAddr=IN.tellg();
                    string tempStr;
                    IN>>tempStr;
                    IN.seekg(tempAddr);
                    if (tempStr == "=")
                    {
                        product = { GrammarItem("ID", true), GrammarItem("=", true), GrammarItem("bool_expr", false) };
                    }
                    else
                    {
                        product = { GrammarItem("bool_expr", false) };
                    }
                }

                for (auto& i : product)
                {
                    i.id = cnt[i.name]++;
                }

                vector<GrammarItem> temp;
                temp.push_back(X);
                currentNoneTerminal= X;
                currentProduction = product;
                cout << X.name << "->";
                for (auto gram : product)
                {
                    temp.push_back(gram);
                    cout << gram.name << " ";
                }
                result.push_back(temp);

                cout << endl;

                if (product[0].name == epsilon)
                {
                    X = stk.top();
                    continue;
                }
                for (int i = product.size() - 1; i >= 0; i--)
                {
                    stk.push(product[i]);
                }
            }
            else
            {
                cout << a.row<<":"<<a.col<<":" << "Error in " << currentNoneTerminal.name << endl;
                cout << "using Production:";
                for (auto gram : currentProduction)
                {
                    cout << gram.name << " ";
                }
                cout << endl;
                cout << a.name <<" is in valid in "<<X.name << endl;
                return 1;
            }
        }
        X = stk.top();
    }
    draw(result);
    return 0;
}

int main()
{

    calcFirst();
    calcFollow();
    calcTable2();
    IN.open("in.txt");
    auto t = predictPrase();
    IN.close();
    if(t)
        cout<<"error"<<endl;
    else
        cout<<"success"<<endl;
    // for(auto production:t)
    // {
    //     for(auto gram:production)
    //     {
    //         cout<<gram.name<<gram.id<<" ";
    //     }
    //     cout<<endl;
    // }


    return 0;
}

/*
E  → T E'
E' → + T E' | ε
T  →  F T'
T' → * F T' | ε
F → ( E ) | id
*/

/*
FOLLOW
计算非终结符 A 的 FOLLOW(A) 时，不断运用以下规则，直到没有新的终结符可以被加入到 FOLLOW(A)

将 $ 放到 FOLLOW(S) 中，S 是开始符，$ 是输入右端的结束标记。

如果存在 A->αBβ，那么 FIRST(β) 中非 ε 的所有符号都在 FOLLOW(B)中。

如果存在 A->αB 或 A->αBβ 且 FIRST(β) 包含 ε，则 FOLLOW(A) 中的所有符号都在 FOLLOW(B) 中。

*/

// ( id + id * ( id + id ) )
// id + id
// id + id * id