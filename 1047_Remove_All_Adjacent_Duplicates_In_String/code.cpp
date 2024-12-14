#include<iostream>
#include<stack>

std::string removeDuplicates(std::string S)
{
    std::string Output = "";
    std::stack<char> s;

    for (const char& c:S)
    {
        if ((!s.empty()) && (c == s.top()))
            s.pop();
        else
            s.push(c);
    }

    while (!s.empty())
        Output = s.top() + Output, s.pop();


    return Output;
}

int main()
{
    std::string Input;
    std::string Output;

    std::cout << "Enter the Expression: ";
    std::cin >> Input;

    Output = removeDuplicates(Input);

    std::cout << "Expression after the duplicates removal: " << Output << std::endl;

    return 0;
}