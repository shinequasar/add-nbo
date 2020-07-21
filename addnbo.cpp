#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h>


int main(int argc, char *argv[]) {
   int count = argc;
   char *fileList[count]; 
   int record_a[20], record_b[20];   ///버 퍼 
   
   for(int i=0; i<count;i++){ // 주어진 인자들 배열에 저 장 
         fileList[i] = argv[i];
    }
   
    printf("\n>> BoB 9기 보안제품개발트랙 : 정소연 <<\n");
    printf(">> 멘토님 : 이경문(gilgil) <<\n\n");
    
      FILE *a_fp, *b_fp; 
      a_fp = fopen(fileList[1],"rt");
      b_fp = fopen(fileList[2],"rt");
      
      if((a_fp == NULL)||( b_fp == NULL)){
         printf(">> 파일 열기 실패.\n\n");
      }
      else{
         printf(">> 파일 읽기 성공!\n\n");
     }
    
	   fread(record_a,4,1,a_fp);
	   uint32_t* ap = reinterpret_cast<uint32_t*>(record_a);
	   uint32_t an = *ap; // TODO
	   
	   an = ntohl(*ap);
	   printf("32a bit number=0x%x\n", an);
	   
	   fread(record_b,4,1,b_fp);
	   uint32_t* bp = reinterpret_cast<uint32_t*>(record_b);
	   uint32_t bn = *bp; // TODO
       bn = ntohl(*bp);
	   printf("32b bit number=0x%x\n", bn);
    
        fclose(a_fp);
        fclose(b_fp);

        uint32_t result = an+bn;

        printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n\n", an, an, bn, bn, result, result);
      
}