#include <stdio.h>
#define BUFLEN 128
int main(int argc, char const *argv[])
{
    FILE *fp_pix=fopen("res.pix","r");
    FILE *fp_hex=fopen("res.h","w");
    char buf[BUFLEN];
    fprintf(fp_hex,"unsigned char res[][8]={");
    while(!feof(fp_pix)){
        unsigned char row=0;
        int i,end;
        fgets(buf,BUFLEN,fp_pix);
        if(buf[0]=='/'){
            fprintf(fp_hex,"\n    ");
            continue;
        }
        for(i=0,end=8;i<8;i++){
            if(buf[i]==0)end=i;
            row=row<<1|(i<end&&buf[i]=='#');
        }
        fprintf(fp_hex,"0x%02x,",row);
    }
    fseek(fp_hex,-1,SEEK_CUR);
    fprintf(fp_hex,"\n}\n");
    fclose(fp_pix);
    fclose(fp_hex);
    return 0;
}
