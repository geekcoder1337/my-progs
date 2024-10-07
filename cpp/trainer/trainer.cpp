#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

long gen(long min,long max)
{
    return min + (rand() % max-min);
}

long ask(std::string word)
{
    ask:
    std::cout << "Enter ";
    for(int i=0;i<word.length();i++)
    {
        std::cout << word[i];
    }
    std::cout << ": ";
    long res;
    try
    {
        std::cin >> res;
    }
    catch(...)
    {
        std::cout << "That's not a number, try again!" << std::endl;
        goto ask;
    }
    return res;
}

int main()
{
    srand((unsigned) time(NULL));

    long min = ask("min number");
    long max = ask("max number");
    long num = ask("number of problems");
    long score = 0;

    for(long i=0; i<num; i++)
    {
        long num1 = gen(min,max) - max/2;
        long num2 = gen(min,max) - max/2;
        short oper = gen(0,1);
        long real_res;
        switch(oper)
        {
            case 0:
                real_res=num1+num2;
                break;
            case 1:
                real_res=num1-num2;
                break;
        }

        ask:
        std::cout << i+1 << ". ";
        
        std::cout << num1;
        switch(oper)
        {
            case 0:
                if (num2 >= 0)
                    std::cout << "+";
                break;
            case 1:
                std::cout << "-";
                break;
        }
        std::cout << num2;
        std::cout << "=";
        long user_in;
        try
        {
            std::cin >> user_in;
        }
        catch(...)
        {
            std::cout << "That's not number, try again!" << std::endl;
            goto ask;
        }
        if(user_in == real_res)
        {
            score++;
            std::cout << "   correct!" << std::endl;
        }
        else
        {
            std::cout << "   uncorrect! (correct is: " << real_res << ")" << std::endl;
        }
    }
    std::cout << std::endl << "Your score is: " << score << std::endl;
    return 0;
}