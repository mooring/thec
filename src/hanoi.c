#include <stdio.h>


void move(char from, char to){
    printf("%c -> %c\n", from, to);
}

void hanoi(int m, char one, char two, char three){
    if(m == 1){
        move(one, three);
    }else{
        hanoi(m-1, one, three, two);
        move(one, three);
        hanoi(m-1, two, one, three);
    }
}

int main(){
    hanoi(3, 'A', 'B','C');
    return 0;
}
