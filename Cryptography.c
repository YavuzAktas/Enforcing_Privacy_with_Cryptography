#include<stdio.h>

int main(void){
	
	int data, backupData, encrypted, backupEncrypted;		//Integer and encrypted integer 
	int digit1, digit2, digit3, digit4;						//Digits of integer
	int x;													//Number of loop
	int remainder;											//Remainder of an integer divided by 10
	int counter = 1;
	
	
	printf("\n----------Enforcing Privacy with Cryptography----------\n\n");
	
	printf("1-)Encrypting\n2-)Decrypting\n3-)Exit\n (Data cannot be decrypted until encrypted ) \n");
	scanf("%d", &x );
	
	while( x != 3 ){
		
		
		if( x == 1 ){
			
			printf("\nEnter data as four digit integers : ");
			scanf("%d", &data );
			
			if( data >= 1 ){
			
				backupData = data;					//Backup of the number
				remainder = ( backupData + 7777 ) % 10 ;		//We will use the remaining number to decrypt
				backupData = ( backupData + 7777 ) / 10;		//We add 7 to each digit of the integer and divide the result by 10
				
				digit4 = backupData / 1000;
				backupData = backupData % 1000;
				
				digit3 = backupData / 100;
				backupData = backupData % 100;
				
				digit2 = backupData / 10;
				
				digit1 = backupData % 10;
				
				backupData = ( digit3 * 1 ) + ( digit4 * 10 ) + ( digit1 * 100 ) + ( digit2 * 1000 );	//swap the first digitwith the third, and swap the second digit with the fourth
				
				printf("Encrypted integer is %d\n\n", backupData );
			
			}
			
			else if( data < 1 ){
				
				printf("You entered wrong data. You are redirected to the menu!!\n\n");
			}
			
		}
		
		
		else if ( x == 2 ){
			
			printf("\nEnter the encrypted four-digit integer : ");
			scanf("%d", &encrypted ); 
			
			if( encrypted >= 1 ){
			
				backupEncrypted = encrypted;
				
				digit4 = backupEncrypted / 1000;
				backupEncrypted = backupEncrypted % 1000;
				
				digit3 = backupEncrypted / 100;
				backupEncrypted = backupEncrypted % 100;
				
				digit2 = backupEncrypted / 10;
				
				digit1 = backupEncrypted % 10;
				
				backupEncrypted  = ( digit3 * 1 ) + ( digit4 * 10 ) + ( digit1 * 100 ) + ( digit2 * 1000 );
				
				backupEncrypted = backupEncrypted * 10 - 7777 + remainder;
				
				printf("Decrypting integer is %d\n\n", backupEncrypted );
			
			}
			
			else if( encrypted < 1 ){
			
				printf("You entered an incorrectly encrypted integer. You are redirected to the menu!!\n\n");
			}
				
		}
		
		else if( x != 1 || x != 2 || x != 3 ){
		
			printf("You chose wrong number. Choose 1, 2 or 3 !!\n");
		}
		
		printf("---------------------------------------------------------\n\n");
		printf("1-)Encrypting\n2-)Decrypting\n3-)Exit\n");
		scanf("%d", &x );
		
	}
	
}

