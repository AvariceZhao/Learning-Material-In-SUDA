
#include <bits/stdc++.h>
#include<fstream>
#include<sstream>
#define epsilon "ε"
using namespace std;
class GrammarItem // 终结符
{
public:
    string name;
    bool isTerminal;
    int id;//表示这个标识符符是当前此标识符的第几个
    GrammarItem(string name, bool isTerminal)
    {
        this->name = name;
        this->isTerminal = isTerminal;
        id = 0;
    }
    GrammarItem(string name, bool isTerminal,int id)
    {
        this->name = name;
        this->isTerminal = isTerminal;
        this->id = id;
    }
    bool operator<(const GrammarItem &item) const
    {

        return this->name < item.name;
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

/*
map<GrammarItem, vector<vector<GrammarItem>>> grammar{
    {GrammarItem("program",false),{{GrammarItem("{",true),GrammarItem("declaration_list",false),GrammarItem("statement_list",false),GrammarItem("}",true)}}},
    {GrammarItem("declaration_list",false),{{GrammarItem(epsilon, true)},{GrammarItem("declaration_listR",false)}}},
    {GrammarItem("declaration_listR",false),{{GrammarItem("declaration_stat",false),GrammarItem("declaration_listR",false)},{GrammarItem(epsilon, true)}}},
    {GrammarItem("declaration_stat",false),{{GrammarItem("int",true),GrammarItem("ID",true),GrammarItem(";",true)}}},
    {GrammarItem("statement_list",false),{{GrammarItem(epsilon, true)},{GrammarItem("statement_listR",false)}}},
    {GrammarItem("statement_listR",false),{{GrammarItem("statement",false),GrammarItem("statement_listR",false)},{GrammarItem(epsilon, true)}}},
    {GrammarItem("statement",false),{{GrammarItem("if_stat",false)},{GrammarItem("while_stat",false)},{GrammarItem("for_stat",false)},{GrammarItem("read_stat",false)},{GrammarItem("write_stat",false)},{GrammarItem("compound_stat",false)},{GrammarItem("expression_stat",false)}}},
    {GrammarItem("if_stat",false),{{GrammarItem("if",true),GrammarItem("(",true),GrammarItem("expression",false),GrammarItem(")",true),GrammarItem("statement",false),GrammarItem("else",true),GrammarItem("statement",false)}}},
    {GrammarItem("while_stat",false),{{GrammarItem("while",true),GrammarItem("(",true),GrammarItem("expression",false),GrammarItem(")",true),GrammarItem("statement",false)}}},
    {GrammarItem("for_stat",false),{{GrammarItem("for",true),GrammarItem("(",true),GrammarItem("expression",false),GrammarItem(";",true),GrammarItem("expression",false),GrammarItem(";",true),GrammarItem("expression",false),GrammarItem(")",true),GrammarItem("statement",false)}}},
    {GrammarItem("write_stat",false),{{GrammarItem("write",true),GrammarItem("expression",false),GrammarItem(";",true)}}},
    {GrammarItem("read_stat",false),{{GrammarItem("read",true),GrammarItem("ID",true),GrammarItem(";",true)}}},
    {GrammarItem("compound_stat",false),{{GrammarItem("{",true),GrammarItem("statement_list",false),GrammarItem("}",true)}}},
    {GrammarItem("expression_stat",false),{{GrammarItem("expression",false),GrammarItem(";",true)},{GrammarItem(";",true)}}},
    {GrammarItem("expression",false),{{GrammarItem("ID",true),GrammarItem("=",true),GrammarItem("bool_expr",false)},{GrammarItem("bool_expr",false)}}},
    {GrammarItem("bool_expr",false),{{GrammarItem("additive_expr",false)},{GrammarItem("additive_expr",false),GrammarItem(">",true),GrammarItem("additive_expr",false)},{GrammarItem("additive_expr",false),GrammarItem("<",true),GrammarItem("additive_expr",false)},{GrammarItem("additive_expr",false),GrammarItem(">=",true),GrammarItem("additive_expr",false)},{GrammarItem("additive_expr",false),GrammarItem("<=",true),GrammarItem("additive_expr",false)},{GrammarItem("additive_expr",false),GrammarItem("==",true),GrammarItem("additive_expr",false)},{GrammarItem("additive_expr",false),GrammarItem("!=",true),GrammarItem("additive_expr",false)}}},
  {GrammarItem("additive_expr",false),{{GrammarItem("term",false)},{GrammarItem("term",false),GrammarItem("+",true),GrammarItem("term",false)},{GrammarItem("term",false),GrammarItem("-",true),GrammarItem("term",false)}}},
    {GrammarItem("term",false),{{GrammarItem("factor",false)},{GrammarItem("factor",false),GrammarItem("*",true),GrammarItem("factor",false)},{GrammarItem("factor",false),GrammarItem("/",true),GrammarItem("factor",false)}}},
   {GrammarItem("factor",false),{{GrammarItem("(",true),GrammarItem("expression",false),GrammarItem(")",true)},{GrammarItem("ID",true)},{GrammarItem("NUM",true)}}},
};

*/
map<GrammarItem, set<GrammarItem>> first, follow;
map<GrammarItem, map<GrammarItem, vector<vector<GrammarItem>>>> table;
void calcFirst()
{

    for (auto &[item, products] : grammar)
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

    bool flag = true;
    while (flag)
    {
        flag = false;
        for (auto &[item, products] : grammar)
        {
            for (auto product : products)
            {
                for (auto gram : product)
                {
                    if (!gram.isTerminal)
                    {
                        for (auto &i : first[gram])
                        {
                            if (i.name != epsilon && first[item].find(i) == first[item].end())
                            {
                                first[item].insert(i);
                                flag = true;
                            }
                        }
                        if (first[gram].find(GrammarItem(epsilon, true)) == first[gram].end())
                        {
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    cout << "-------------------First:-----------------------" << endl;
    for (auto &item : first)
    {
        cout << item.first.name << ": ";
        for (auto &i : item.second)
        {
            cout << i.name << " ";
        }
        cout << endl;
    }
    cout << "-------------------First:-----------------------" << endl;
}

void calcFollow()
{
    follow[GrammarItem("E", false)].insert(GrammarItem("$", true));
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (auto &[item, products] : grammar) // 枚举每个非终结符
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
                                for (auto &k : first[product[j]]) // 遍历这个非终结符的first
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
                            for (auto &k : follow[item])
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
                                for (auto &k : follow[item])
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
    cout << "-------------------Follow:-----------------------" << endl;
    for (auto &item : follow)
    {
        cout << item.first.name << ": ";
        for (auto &i : item.second)
        {
            cout << i.name << " ";
        }
        cout << endl;
    }
    cout << "-------------------Follow:-----------------------" << endl;
}



void calcTable2()
{
      for (auto &[item, products] : grammar) // 遍历每个非终结符
    {
       for (auto& product : products) // 遍历非终结符的每个产生式
        {
            bool flag = 1;
            for (int i = 0; i < product.size();i++)
            {
                if(product[i].name==epsilon)
                    continue;
                
                if(product[i].isTerminal&&product[i].name!=epsilon)
                {
                    table[item][product[i]].push_back(product);
                    flag = 0;
                    break;
                }
                else
                {
                  
                    
                    for(auto& j:first[product[i]])
                    {
                        if(j.name!=epsilon)
                        {
                            table[item][j].push_back(product);
                        }
                    }
                    //非终结符推不出空
                    if(first[product[i]].find(GrammarItem(epsilon,true))==first[product[i]].end())
                    {
                        flag = 0;
                        break;
                    }
                }
            }
        if(flag)
        {
            for(auto ch:follow[item])
            {
                    table[item][ch].push_back(product);
            }    
            if(follow[item].find(GrammarItem("$",true))==follow[item].end())
            {{
                        table[item][GrammarItem("$", true)].push_back(product);
            }}
        }
        }
      
    }

    cout << "-------------------Table:-----------------------" << endl;
    // map<GrammarItem, map<GrammarItem, vector<GrammarItem>>> table;
    for (auto [item, mp] : table)
    {
        cout << item.name << ":\n";
        for (auto [ch, products] : mp)
        {
            for(auto product:products)
            {
            cout << ch.name << "->";
            for (auto gram : product)
            {
                cout << gram.name << " ";
            }
            cout <<"|";
            }
            cout << endl;
        }

        cout<<endl;
    }
}
void calcTable()
{
    /*
    对于一个文法G的每个产生式A→α，进行如下处理：

对于FIRST(α)中的每个终结符号a，将A→α加入到M[A,α]。

如果ε在FIRST(α)中，那么对于FOLLOW(A)中的每个终结符号b，将A→α加入到M[A,α]中。如果ε在FIRST(α)中，且$在FOLLOW(A)中，也将A→α加入到M[A,$]。

    */
    for (auto &[item, products] : grammar) // 遍历每个非终结符
    {
        if(item.name=="E'")
        {



        for (auto product : products) // 遍历非终结符的每个产生式
        {

            auto alpha = product[0];

            if (!alpha.isTerminal)//非终结符看first集合
            {
                for (auto ch : first[alpha])
                {
                    if (ch.isTerminal)
                    {
                        table[item][ch].push_back(product);
                    }
                }

                if (first[alpha].count(GrammarItem(epsilon, true)))
                {
                    for (auto b : follow[item])
                    {
                        table[item][b].push_back(product);
                    }

                    if (follow[item].count(GrammarItem("$", true)))
                    {
                        table[item][GrammarItem("$", true)].push_back(product);
                    }
                }
            }
            //终结符
            else if (alpha.name != epsilon)//如果不是空
            {
               
                table[item][alpha].push_back(product);
            }
            else 
            {
                if(alpha.name==epsilon&&follow[item].count(GrammarItem("$", true)))
                {
                    table[item][GrammarItem("$", true)].push_back(product);
                }
            }

            if(first[item].count(GrammarItem(epsilon, true)))
            {
                for (auto b : follow[item])
                {
                    table[item][b].push_back(product);
                }
            }
        }



        }
    }

    cout << "-------------------Table:-----------------------" << endl;
    // map<GrammarItem, map<GrammarItem, vector<GrammarItem>>> table;
    for (auto [item, mp] : table)
    {
        cout << item.name << ":\n";
        for (auto [ch, products] : mp)
        {
            for(auto product:products)
            {
            cout << ch.name << "->";
            for (auto gram : product)
            {
                cout << gram.name << " ";
            }
            cout <<"|";
            }
            cout << endl;
        }

        cout<<endl;
    }
}
vector<vector<GrammarItem>> predictPrase()
{
    vector<vector<GrammarItem>> result;
    stack<GrammarItem> stk;
    map<string, int> cnt;
    stk.push(GrammarItem("$", true,cnt["$"]++));
    stk.push(GrammarItem("E", false,cnt["E"]++));
    string str;
    cin >> str;
    GrammarItem X=stk.top();
    GrammarItem a=GrammarItem(str,true);
    while (X.name != "$")
    {
        if (X.isTerminal)
        {
            if (X.name == a.name)
            {
            //  cout<<"match "<<a.name<<endl;
                stk.pop();
                cin >> str;
                a = GrammarItem(str, true);

            }
            else
            {
                cout << "[ERROR] expected " << X.name << " but get " << a.name << endl;
                 exit(0);
            }
        }
        else
        {
            if (table[X].find(a) != table[X].end())
            {
                stk.pop();
                auto products = table[X][a];
                auto product=products[0];
                for(auto &i:product)
                {
                    i.id=cnt[i.name]++;
                }

                vector<GrammarItem> temp;
                temp.push_back(X);
                cout<<X.name<<"->";
                for(auto gram:product)
                {
                    temp.push_back(gram);
                    cout<<gram.name<<" ";
                   
                   // cout << "\"" << X.name << "\"->\"" << gram.name << "\";";
                }
                result.push_back(temp);
                
                cout<<endl;
              
                if(product[0].name==epsilon)
                {
                    X=stk.top();
                    continue;
                }
                for (int i = product.size() - 1; i >= 0; i--)
                {
                    stk.push(product[i]);
                }
              
            }
            else
            {
                cout << "[ERROR] invalid synax" << endl;
                exit(0);
            }
        }
        X = stk.top();
    }
    return result;
}
void draw(vector<vector<GrammarItem>>result)
{
     cout << "-------------------draw:-----------------------" << endl;
   
  //在点的字符串里添加的空格数
    vector<string>drawFile;
    drawFile.push_back("digraph G {");
   // drawFile.push_back("node [shape = circle];");
    drawFile.push_back("graph [ratio = 1];");
    for(auto production:result)
    {
        auto head=production[0].name;
        string s;
        stringstream ss(s);
        ss<<production[0].id;
        head=head+"_"+ss.str();


        drawFile.push_back("\""+head+"\"[label=\""+production[0].name+"\"];");
     //   cnt[production[0]]++;


        for(int i=1;i<production.size();i++)
        {  
            string str=production[i].name;
         
            string s;
            stringstream ss(s);
            ss<<production[i].id;
            str=str+"_"+ss.str();
            drawFile.push_back("\""+str+"\"[label=\""+production[i].name+"\"];");
            drawFile.push_back("\""+head+"\""+"->"+"\""+str+"\";");
    
            //if(!production[i].isTerminal)
          //      continue;
          
        }
        
    }
    drawFile.push_back("}");
    ofstream out("draw.dot");
    for(auto str:drawFile)
    {
        out<<str<<endl;
    }
    out.close();
    system("dot -Tpng draw.dot -o draw.png");
    

}
int main()
{
    calcFirst();
    calcFollow();
    calcTable2();
   auto t=predictPrase();
    
    draw(t);
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