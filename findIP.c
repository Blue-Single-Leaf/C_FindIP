#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../myinput.c"
#include "../myfile.c"
void main(int argc,char *argv[]){
	char *start_ip;
	char *end_ip;
	char *s_ip[5];
	char *e_ip[5];
	FILE *fp;
	FILE *fp2;
	FILE *fp3;
	int sip[5] = {-1,-1,-1,-1,-2};
	int eip[5] = {-1};
	int i;
	char my_ping[64];
	char my_ip[32];
	char *ping = my_ping;
	char *ip = my_ip;
	start_ip = getsStr("please input the start IP address: ").c;
	end_ip = getsStr("please input the end IP address: ").c;
	s_ip[0] = strtok(start_ip,".");
	i = 0;
	while(s_ip[i] != NULL){
		i++;
		s_ip[i] = strtok(NULL,".");
	}
	for(i = 0;i<4;i++)
		sip[i]	= atoi(s_ip[i]);
	e_ip[0] = strtok(end_ip,".");
	i = 0;
	while(e_ip[i] != NULL){
		i++;
		e_ip[i] = strtok(NULL,".");
	}
	for(i = 0;i<4;i++)
		eip[i]	= atoi(e_ip[i]);
					
	while(sip[0] < eip[0]){
		while(sip[1] <= 254){
			while(sip[2] <= 254){
				while(sip[3] <= 254){
					sprintf(ip,"%d.%d.%d.%d",sip[0],sip[1],sip[2],sip[3]);			//或许有问题
					sprintf(ping,"ping -n 1 %s >e:/temp.txt",ip);
					printf("\t正在ping %s\n",ip);
					system(ping);
					if((fp = fopen("e:/temp.txt","rb")) == NULL){
						printf("can't open this file");
						exit(0);
					}
					fgotoline(fp,3);
					if(fgotostr(fp,"请求超时") == 1){
						printf("ping %s 失败\n",ip);
						sprintf(ip,"%s\n",ip);
						fp2 = fopen("e:/badIp.txt","a");
						fwrite(ip,strlen(ip),1,fp2);
						fclose(fp2);
					}
					else{
						printf("ping %s 成功\n",ip);
						sprintf(ip,"%s\n",ip);
						fp2 = fopen("e:/goodIp.txt","a");
						fwrite(ip,strlen(ip),1,fp2);
						fclose(fp2);
						
					}
					fclose(fp);
					sip[3]++;

				}
				sip[3] = 0;
				sip[2]++;
			}
			sip[2] = 0;
			sip[1]++;
		}
		sip[1] = 0;
		sip[0]++;
	}
	while(sip[1] < eip[1]){
		while(sip[2] <= 254){
			while(sip[3] <= 254){
				sprintf(ip,"%d.%d.%d.%d",sip[0],sip[1],sip[2],sip[3]);			//或许有问题
				sprintf(ping,"ping -n 1 %s >e:/temp.txt",ip);
				printf("\t正在ping %s\n",ip);
				system(ping);
				if((fp = fopen("e:/temp.txt","rb")) == NULL){
					printf("can't open this file");
					exit(0);
				}
				fgotoline(fp,3);
				if(fgotostr(fp,"请求超时") == 1){
						printf("ping %s 失败\n",ip);
						sprintf(ip,"%s\n",ip);
						fp2 = fopen("e:/badIp.txt","a");
						fwrite(ip,strlen(ip),1,fp2);
						fclose(fp2);
					}
					else{
						printf("ping %s 成功\n",ip);
						sprintf(ip,"%s\n",ip);
						fp2 = fopen("e:/goodIp.txt","a");
						fwrite(ip,strlen(ip),1,fp2);
						fclose(fp2);
						
					}
				sip[3]++;

			}
			sip[3] = 0;
			sip[2]++;
		}
		sip[2] = 0;
		sip[1]++;
	}
	while(sip[2] < eip[2]){
			while(sip[3] <= 254){
				sprintf(ip,"%d.%d.%d.%d",sip[0],sip[1],sip[2],sip[3]);			//或许有问题
				sprintf(ping,"ping -n 1 %s >e:/temp.txt",ip);
				printf("\t正在ping %s\n",ip);
				system(ping);
				if((fp = fopen("e:/temp.txt","rb")) == NULL){
					printf("can't open this file");
					exit(0);
				}
				fgotoline(fp,3);
				if(fgotostr(fp,"请求超时") == 1){
						printf("ping %s 失败\n",ip);
						sprintf(ip,"%s\n",ip);
						fp2 = fopen("e:/badIp.txt","a");
						fwrite(ip,strlen(ip),1,fp2);
						fclose(fp2);
					}
					else{
						printf("ping %s 成功\n",ip);
						sprintf(ip,"%s\n",ip);
						fp2 = fopen("e:/goodIp.txt","a");
						fwrite(ip,strlen(ip),1,fp2);
						fclose(fp2);
						
					}
				sip[3]++;

			}
			sip[3] = 0;
			sip[2]++;
		}
	while(sip[3] <= eip[3]){
				sprintf(ip,"%d.%d.%d.%d",sip[0],sip[1],sip[2],sip[3]);			//或许有问题
				sprintf(ping,"ping -n 1 %s >e:/temp.txt",ip);
				printf("\t正在ping %s\n",ip);
				system(ping);
				if((fp = fopen("e:/temp.txt","rb")) == NULL){
					printf("can't open this file");
					exit(0);
				}
				fgotoline(fp,3);
				if(fgotostr(fp,"请求超时") == 1){
						printf("ping %s 失败\n",ip);
						sprintf(ip,"%s\n",ip);
						fp2 = fopen("e:/badIp.txt","a");
						fwrite(ip,5*sizeof(ip),1,fp2);
						fclose(fp2);
					}
					else{
						printf("ping %s 成功\n",ip);
						sprintf(ip,"%s\n",ip);
						fp2 = fopen("e:/goodIp.txt","a");
						fwrite(ip,5*sizeof(ip),1,fp2);
						fclose(fp2);
						
					}
				sip[3]++;

			}
	
	
}
