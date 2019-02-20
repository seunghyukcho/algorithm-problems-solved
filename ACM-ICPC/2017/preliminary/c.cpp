#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int main()
{
  int w;
  stack<char> sp;
  string input;
  cin >> w;
  getline(cin, input);
  getline(cin, input);
  int v = 0, ef = 0, eb = 0;
  bool is_end = true;
  bool is_strange = false;
  char last = 'S';
  for(int i = 0 ;i < input.size(); i++)
  {
    if(input[i] == ' ')
    {
      continue;
    }
    else if(input[i] == 'S')
    {
      if(!is_end)
      {
        is_strange = true;
        break;
      }
      v+=1;
      ef+=1;
      is_end = false;
      last = input[i];
    }
    else if(input[i] == 'L')
    {
      if(!is_end)
      {
        is_strange = true;
        break;
      }
      v+=2;
      ef+=2;
      eb+=1;
      is_end = false;
      last = input[i];
    }
    else if(input[i] == 'B')
    {
      if(!is_end)
      {
        is_strange = true;
        break;
      }
      v+=2;
      ef+=3;
      is_end = false;
      last = input[i];
    }
    else if(input[i] == ',')
    {
      if(is_end)
      {
        is_strange = true;
        break;
      }
      is_end = true;
    }
    else if(i && input[i] == '(')
    {
      if(last != 'L' && last != 'B')
      {
        is_strange = true;
        break;
      }
      sp.push(input[i]);
      is_end = true;
      last = 'S';
    }
    else if(i && input[i] == '[')
    {
      if(last != 'L' && last != 'B')
      {
        is_strange = true;
        break;
      }
      sp.push(input[i]);
      is_end = true;
      last = 'S';
    }
    else if(input[i] == ')')
    {
      if(sp.size() == 0 || sp.top() != '(')
      {
        is_strange = true;
        break;
      }
      sp.pop();
    }
    else if(input[i] == ']')
    {
      if(sp.size() == 0 || sp.top() != '[')
      {
        is_strange = true;
        break;
      }
      sp.pop();
    }
    else
    {
      is_strange = true;
      break;
    }
  }
  if(is_strange || is_end || sp.size())
  {
    printf("-1\n");
    return 0;
  }
  printf("%d\n", ef+(w*eb)-v+1);
  return 0;
}
