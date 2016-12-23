#include <stdio.h>

int main(){
	int a=0;
	char *str = "korea" //포인터변수
	str = "japen"; // 새로운 주소값을 넣어준다는 의미이므로 가능
	scanf("%s",str); //(x) 에러발생 상수 원본을 바꾸려고 하기 때문에
	scanf("%d",&a);

	char str2[20];
	//배열의 이름은 배열의 첫번째 요소의 주소값으로 대치된다. 
	//그순간부터배열명이 곧 주소값이 된다.이시점부터는 상수가 되버린다
	str2="orange"; //(x) 에러발생
	scanf("%s",str2); 

return 0;
}