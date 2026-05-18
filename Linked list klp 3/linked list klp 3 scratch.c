#include <stdio.h>
#include<stdlib.h>




struct ll {
    int data;
    struct ll *next;
};



int cari(struct ll  *head) {
    struct ll *curr = head;
    struct ll *arr[13];
    int i=0;
    int j;
    while (curr != NULL) {


        arr[i]=curr;
        curr = curr->next;
        i++;
        j=0;
        while (j<i) {



            if (arr[j]==curr) {
                printf("ada cycle pada linked list karena ada pengulangan alamat yaitu %d pada node   ke-%d kembali ke node ke-%d",curr,i-1,j);
                return j;
            }


            j++;
        };


    }
    printf("tidak ada pengulangan pada linked list");
    return -1;
}



int main(void) {

    struct ll *nol=NULL;
    nol =(struct ll*)malloc(sizeof(struct ll));
    struct ll *satu=NULL;
    satu =(struct ll*)malloc(sizeof(struct ll));
    struct ll *dua=NULL;
    dua =(struct ll*)malloc(sizeof(struct ll));
    struct ll *tiga=NULL;
    tiga =(struct ll*)malloc(sizeof(struct ll));
    struct ll *empat=NULL;
    empat =(struct ll*)malloc(sizeof(struct ll));




    nol->data=11;
    nol->next=satu;
    satu->data=10;
    satu->next = dua;
    dua->data=20;
    dua->next=tiga;
    tiga->data=20;
    tiga->next=empat;
    empat->data=20;
    empat->next=satu;








    //cek apakah ada siklus
    int c= cari(nol) ;


    printf("\n\nPOS = %d",c);

    free (nol) ;
    free (satu) ;
    free (dua) ;
    free (tiga) ;
    free (empat) ;

}

