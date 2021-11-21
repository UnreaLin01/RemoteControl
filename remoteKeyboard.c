#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

int findPos(char data, int posType){

    char layout[6][8] = {
                        {'a', 'b', 'c', 'd', 'e', '1', '2', '3'},
                        {'f', 'g', 'h', 'i', 'j', '4', '5', '6'},
                        {'k', 'l', 'm', 'n', 'o', '7', '8', '9'},
                        {'p', 'q', 'r', 's', 't', '.', '@', '0'},
                        {'u', 'v', 'w', 'x', 'y', 'z', '_', '/'},
                        { -1, ' ',   0,   0,   0,   0,   0,   0}
                        };
    int y = 0;
    int x = 0;
    int result = -1;
    for(y = 0; y < 6; y++){
        for(x = 0; x < 8; x++){
            if(data == layout[y][x]){
                if(posType == 0){
                    result = x;
                }else if(posType == 1){
                    result = y;
                }
            }
        }
    }
    return result;
}

void main(){

    int num = 0;
    char data[50] = {};
    //scanf stop reading when read the space
    scanf("%d",&num);
    fflush(stdin);
    //fgets stop reading when read the newline
    fgets(data, num + 1, stdin);

    //position storage
    //index 0 = x pos
    //index 1 = y pos
    int prePos[2] = {0,0};
    int nowPos[2] = {0,0};
    //case storage
    //lower-case = 0
    //upper-case = 1
    int _case = 0;
    int steps = 0;

    int index = 0;
    for(index = 0; index < num; index++){
        
        char currentData = data[index];

        int changeCase = 0;
        if(_case == 0 && currentData > 'A' && currentData < 'Z'){
            _case = 1;
            changeCase = 1;
        }else if(_case == 1 && currentData > 'a' && currentData < 'z'){
            _case = 0;
            changeCase = 1;
        }

        if(changeCase == 1){
            nowPos[0] = findPos(-1, 0);
            nowPos[1] = findPos(-1, 1);
            steps += abs(nowPos[0] - prePos[0]);
            steps += abs(nowPos[1] - prePos[1]);
            steps += 1;//press aA
            printf("Move(%d,%d)->(%d,%d)", prePos[0], prePos[1], nowPos[0], nowPos[1]);
            printf(" Select(%d,%d)", nowPos[0], nowPos[1]);
            printf(" %d\n",steps);
            prePos[0] = nowPos[0];
            prePos[1] = nowPos[1];
        }

        if(_case == 1){
            currentData = tolower(currentData);
        }
        nowPos[0] = findPos(currentData, 0);
        nowPos[1] = findPos(currentData, 1);
        steps += abs(nowPos[0] - prePos[0]);
        steps += abs(nowPos[1] - prePos[1]);
        steps += 1;//selection
        printf("Move(%d,%d)->(%d,%d)", prePos[0], prePos[1], nowPos[0], nowPos[1]);
        printf(" Select(%d,%d)", nowPos[0], nowPos[1]);
        printf(" %d\n",steps);
        prePos[0] = nowPos[0];
        prePos[1] = nowPos[1];
    }
    steps++;
    printf("Enter %d", steps);
}