#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h>


 uint32_t readFile(int record[], int size, int count, FILE *fp){ //함수 형태로 반복되는 건 빼주기
      fread(record,size,count,fp);
	   uint32_t* p = reinterpret_cast<uint32_t*>(record);
	   uint32_t n = *p; // TODO
	   n = ntohl(*p);
	   printf("32a bit number=0x%x\n", n);
      fclose(fp);
      return n;
}


int main(int argc, char *argv[]) {
   int record_a[20], record_b[20];   ///버퍼 

    printf("\n>> BoB 9기 보안제품개발트랙 : 정소연 <<\n");
    printf(">> 멘토님 : 이경문(gilgil) <<\n\n");
    
      FILE *a_fp, *b_fp; 
      a_fp = fopen(argv[1],"rt");
      b_fp = fopen(argv[2],"rt");
      
      if((a_fp == NULL)||( b_fp == NULL)){
         printf(">> 파일 열기 실패.\n\n");
      }
      else{
         printf(">> 파일 읽기 성공!\n\n");
     }
    
      uint32_t an = readFile(record_a,4,1,a_fp);
      uint32_t bn = readFile(record_b,4,1,b_fp);
	
      uint32_t result = an+bn;

      printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n\n", an, an, bn, bn, result, result);
      
}