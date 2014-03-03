#include <stdio.h>
#include <stdlib.h>

char *operator[64] = {
		"+++", "++-", "++*", "++/",  //0-3
		"+-+", "+--", "+-*", "+-/",  //4-7
		"+*+", "+*-", "+**", "+*/",  //8-11
		"+/+", "+/-", "+/*", "+//",  //12-15
		"-++", "-+-", "-+*", "-+/",  //16-19
		"--+", "---", "--*", "--/",  //20-23
		"-*+", "-*-", "-**", "-*/",  //24-27
		"-/+", "-/-", "-/*", "-//",  //28-31
		"*++", "*+-", "*+*", "*+/",  //32-35
		"*-+", "*--", "*-*", "*-/",  //36-39
		"**+", "**-", "***", "**/",  //40-43
		"*/+", "*/-", "*/*", "*//",  //44-47
		"/++", "/+-", "/+*", "/+/",  //48-51
		"/-+", "/--", "/-*", "/-/",  //52-55
		"/*+", "/*-", "/**", "/*/",  //56-59
		"//+", "//-", "//*", "///",  //60-63
};


float operation(float a, float b, char c)
{
	switch (c){
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		default:
			return 0.0;		
	}
}

float op(int a[], int n, char *op, int method)
{
	float tmp1;
	float tmp2;
	float tmp3;
	switch (method){
		case 0:  
			tmp1 = operation(a[0], a[1], op[0]);
			tmp2 = operation(tmp1, a[2], op[1]);
			tmp3 = operation(tmp2, a[3], op[2]);
			break;
		case 1:
			tmp1 = operation(a[0], a[1], op[0]);
			tmp2 = operation(a[2], a[3], op[2]);
			tmp3 = operation(tmp1, tmp2, op[1]);
			break;
		case 2:
			tmp1 = operation(a[1], a[2], op[1]);
			tmp2 = operation(a[0], tmp1, op[0]);
			tmp3 = operation(tmp2, a[3], op[2]);
			break;
		case 3:
			tmp1 = operation(a[1], a[2], op[1]);
			tmp2 = operation(tmp1, a[3], op[2]);
			tmp3 = operation(a[0], tmp2, op[0]);
			break;
		/* case 4:
			tmp1 = operation(a[2], a[3], op[2]);
			tmp2 = operation(a[0], a[1], op[0]);
			tmp3 = operation(tmp1, tmp2, op[1]);
			break; */
		case 4:
			tmp1 = operation(a[2], a[3], op[2]);
			tmp2 = operation(a[1], tmp1, op[1]);
			tmp3 = operation(a[0], tmp2, op[0]);
			break;
		default:
			break;
	}
	
	return tmp3;
}


int main()
{
	
	int a=0, b=0, c=0, d=0;
	int operand[24][4];
	int i, j, k, l;
	float tmp;

	scanf("%d%d%d%d", &a, &b, &c, &d);
	for(i = 0; i < 24; i++){
		if(i < 6){
			operand[i][0] = a;
			switch (i){
				case 0:
					operand[i][1] = b;
					operand[i][2] = c;
					operand[i][3] = d;
					break;
				case 1:
					operand[i][1] = b;
					operand[i][2] = d;
					operand[i][3] = c;
					break;
				case 2:
					operand[i][1] = c;
					operand[i][2] = b;
					operand[i][3] = d;
					break;
				case 3:
					operand[i][1] = c;
					operand[i][2] = d;
					operand[i][3] = b;
					break;
				case 4:
					operand[i][1] = d;
					operand[i][2] = b;
					operand[i][3] = c;
					break;
				case 5:
					operand[i][1] = d;
					operand[i][2] = c;
					operand[i][3] = b;
					break;
				default:
					break;
			}
		}else if(i >= 6 && i < 12){
			operand[i][0] = b;
			switch (i){
				case 6:
					operand[i][1] = a;
					operand[i][2] = c;
					operand[i][3] = d;
					break;
				case 7:
					operand[i][1] = a;
					operand[i][2] = d;
					operand[i][3] = c;
					break;
				case 8:
					operand[i][1] = c;
					operand[i][2] = a;
					operand[i][3] = d;
					break;
				case 9:
					operand[i][1] = c;
					operand[i][2] = d;
					operand[i][3] = a;
					break;
				case 10:
					operand[i][1] = d;
					operand[i][2] = a;
					operand[i][3] = c;
					break;
				case 11:
					operand[i][1] = d;
					operand[i][2] = c;
					operand[i][3] = a;
					break;
				default:
					break;
			}
		}else if(i >= 12 && i < 18){
			operand[i][0] = c;
			switch (i){
				case 12:
					operand[i][1] = a;
					operand[i][2] = b;
					operand[i][3] = d;
					break;
				case 13:
					operand[i][1] = a;
					operand[i][2] = d;
					operand[i][3] = b;
					break;
				case 14:
					operand[i][1] = b;
					operand[i][2] = a;
					operand[i][3] = d;
					break;
				case 15:
					operand[i][1] = b;
					operand[i][2] = d;
					operand[i][3] = a;
					break;
				case 16:
					operand[i][1] = d;
					operand[i][2] = a;
					operand[i][3] = b;
					break;
				case 17:
					operand[i][1] = d;
					operand[i][2] = b;
					operand[i][3] = a;
					break;
				default:
					break;
			}
		}else{
			operand[i][0] = d;
			switch (i){
				case 18:
					operand[i][1] = a;
					operand[i][2] = b;
					operand[i][3] = c;
					break;
				case 19:
					operand[i][1] = a;
					operand[i][2] = c;
					operand[i][3] = b;
					break;
				case 20:
					operand[i][1] = b;
					operand[i][2] = a;
					operand[i][3] = c;
					break;
				case 21:
					operand[i][1] = b;
					operand[i][2] = c;
					operand[i][3] = a;
					break;
				case 22:
					operand[i][1] = c;
					operand[i][2] = a;
					operand[i][3] = b;
					break;
				case 23:
					operand[i][1] = c;
					operand[i][2] = b;
					operand[i][3] = a;
					break;
				default:
					break;
			}
		}
	}
	
	
	for(j = 0; j < 24; j++){
		for(k = 0; k < 64; k++){
			for(l = 0; l < 5; l++){
				tmp = op(operand[j], 4, operator[k], l);
				if(tmp == 24.0){
					//printf("j = %d, k = %d, l = %d\n", j, k, l);
					switch (l){
						case 0:
							printf("((%d%c%d)%c%d)%c%d", operand[j][0], operator[k][0], operand[j][1], 
								operator[k][1], operand[j][2], operator[k][2], operand[j][3]);
							break;
						case 1:
							printf("(%d%c%d)%c(%d%c%d)", operand[j][0], operator[k][0], operand[j][1], 
								operator[k][1], operand[j][2], operator[k][2], operand[j][3]);
							break;
						case 2:
							printf("(%d%c(%d%c%d))%c%d", operand[j][0], operator[k][0], operand[j][1], 
								operator[k][1], operand[j][2], operator[k][2], operand[j][3]);
							break;
						case 3:
							printf("%d%c((%d%c%d)%c%d)", operand[j][0], operator[k][0], operand[j][1], 
								operator[k][1], operand[j][2], operator[k][2], operand[j][3]);
							break;
						case 4:
							printf("%d%c(%d%c(%d%c%d))", operand[j][0], operator[k][0], operand[j][1], 
								operator[k][1], operand[j][2], operator[k][2], operand[j][3]);
							break;
						default:
							break;
					}
					return 0;
				}
			}
		}
	}
	printf("-1\n");
	return 0;

/* 	tmp = op(operand[6], 4, operator[24], 0); //((3-2)*12)+12
	printf("%f", tmp);
	tmp = op(operand[0], 4, operator[39], 1); //(5*5)-(5/5)
	printf("%f", tmp);
	tmp = op(operand[1], 4, operator[8], 2);//(1+(3*6))+5
	printf("%f", tmp);
	tmp = op(operand[0], 4, operator[6], 3); //8+((13-9)*4)
	printf("%f", tmp);
	tmp = op(operand[0], 4, operator[39], 4); //2*(13-(7/7))
	printf("%f", tmp);
	if(tmp == 24){
		printf("got it\n");
	}else{
		printf("shit\n");
	} */
	
}

