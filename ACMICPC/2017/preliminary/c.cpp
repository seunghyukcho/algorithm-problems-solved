#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
    stack<char> sp;
    int w;
    string input;
    cin >> w >> input;

    bool is_end = false;
    char last;
    bool strange = false;
    int v = 0, ef = 0, eb = 0;
    for(int i = 0; i < input.size(); i++)
    {
        if(input[i] == ' ') continue;
        else if(input[i] == 'S')
        {
            if(is_end == true)
            {
                printf("s strange\n");
                strange = true;
                break;
            }
            is_end = true;
            v++;
            ef++;
            last = input[i];
        }
        else if(input[i] == 'L')
        {
            if(is_end == true)
            {
                printf("l strange\n");
                printf("%d\n", i);
                strange = true;
                break;
            }
            is_end = true;
            v++;
            ef+=2;
            eb+=1;
            last = input[i];
        }
        else if(input[i] == 'B')
        {
            if(is_end == true)
            {
                printf("b strange\n");
                strange = true;
                break;
            }
            is_end = true;
            v++;
            ef++;
            last = input[i];
        }
        else if(input[i] == ',')
        {
            if(is_end == false)
            {
                printf(", strange\n");
                strange = true;
                break;
            }
            is_end = false;
            last = input[i];
        }
        else if(i && (input[i] == '(' || input[i] == '['))
        {
            if(last != 'L' && last != 'B')
            {
                printf("(, [ strange\n");
                printf("%d %c\n", i, last);
                strange = true;
                break;
            }
            sp.push(input[i]);
            is_end = false;
            last = input[i];
        }
        else if(i && input[i] == ')')
        {
            if(sp.top() != '(')
            {
                printf(") strange\n");
                strange = true;
                break;
            }
            v++;
            sp.pop();
            last = input[i];
        }
        else if(i && input[i] == ']')
        {
            if(sp.top() != '[')
            {
                printf("] strange\n");
                strange = true;
                break;
            }
            v++;
            sp.pop();
            last = input[i];
        }
        else
        {
            printf("string strange\n");
            strange = true;
            break;
        }
    }
    if(strange)
    {
        printf("-1\n");
        return 0;
    }
    printf("%d %d %d %d\n", ef, eb, v, w);
    printf("%d\n", ef+(w*eb)+2-v);
}
