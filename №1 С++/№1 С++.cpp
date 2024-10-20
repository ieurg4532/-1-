#include <iostream>
#include <stack>

using namespace std; // Використання простору імен std


void FullStack(stack<int>& Stack, int size); // Функція заповнення стеку
void Sort(stack<int>& Stack, stack<int>& Stack1, stack<int>& Stack2); // Функція для перенесення чисел
void Show(stack<int>& Stack); // Функція виводу на екран

int main()
{
    srand(time(NULL));

    cout << "Enter your option: ";
    int variant;
    cin >> variant; 

    int S = variant * 5 + 50; // Обчислення розміра стеку

    stack<int> Stack_main; // Створення cтеку
    
    FullStack(Stack_main, S); // Визов функції 

    stack<int> Stack1;
    stack<int> Stack2;

    Sort(Stack_main, Stack1, Stack2);

    cout << "Paired numbers: \n"; 
    Show(Stack1);
    cout << "Unpaired numbers: \n";
    Show(Stack2);

    return 0; 
}

void FullStack(stack<int>& Stack, int size){
    for (int i = 0; i < size; i++) {
        int num = rand() % 1000 + 1; 
        Stack.push(num);
    }
}

void Sort(stack<int>& Stack, stack<int>& Stack1, stack<int>& Stack2) {
    while(!Stack.empty()) {
        if (Stack.top() % 2 == 0) {
            Stack1.push(Stack.top());
            Stack.pop();
        }
        else {
            Stack2.push(Stack.top());
            Stack.pop();
        }
    }
}

void Show(stack<int>& Stack) {
    while(!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop(); 
    }
    cout << endl;
}
