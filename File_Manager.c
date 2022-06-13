#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// create_file() fonksiyonu yeni bir dosya olusturur.
void create_file(char *file_name)
{
    // fopen fonksiyonu olusturmak istedigimiz dosyanin adini uzantisi ile veriyoruz ve "w" komutu sayesinde bos bir dosya olusturuyoruz.
	FILE *fp;

	fp = fopen(file_name,"w");
	
    // Dosya kontrolu
	if (fp == NULL)
	{
		printf("HATA!!!! DOSYA OLUSTURULAMADI \n");
	}
	else
	{
		printf("DOSYA OLUSTURULDU..\n");
	
	}
    // dosya kapatiliyor.
    fclose(fp);
}

// delete_file() fonksiyonu var olan dosyayi siler.
void delete_file(char *file_name)
{
    // remove() fonksiyonu kullanarak silmek istedigimiz dosyanin adini uzantisi ile birlikte giriyoruz ve dosyamiz siliniyor.
	if(remove(file_name)== 0 )
	{
		printf("DOSYA BASARI ILE SILINDI..\n");
	}
	else
	{
		printf("BOYLE BIR DOSYA BULUNAMADI.\n");
	}

}

// rename_file() fonksiyonu var olan dosyanin ismini degistirir.
void rename_file(char *file_name, char *file_rename)
{
	// rename() fonksiyonu ile adini değiştirmek istediğimiz dosyanin adini ve yeni adini arguman olarak vererek dosyanin adini kolayca degistiriyoruz.
    int re = rename(file_name, file_rename);

    // rename kontrolu
	if(re == 0)
	{
		printf("DOSYA ADI BASARI ILE DEGISTIRILDI..\n");
	
	}
	else
	{
		printf("BOYLE BIR DOSYA BULUNAMADI.\n");
	}


}

// file_copying() fonksiyonu dosya kopyalama islemini gerceklestirir.
void file_copying(char *file_name, char *copy_name )
{
    char ch;
    FILE *source, *target;

    // fopen ile dosyayi okuma modunda aciyoruz.
    source = fopen(file_name, "r");

    // dosya acilmazsa ekrana yazdirilacak mesaj.
    if (source == NULL) {
       printf("HATALI DOSYA ADI...\n");

    }
    
    //fopen ile yeni kopya dosyasini yazma modunda aciyoruz içinde değer varsa silinsin ya da dosya yoksa olusturulsun diye. 
    target = fopen(copy_name, "w");
    
    // dosya kontrolu
    if (target == NULL) {
       fclose(source);
       printf("HATAA...\n");
    }

    //fgetc ile dosyanin sonuna kadar giderek alinan tek tek degerleri diger dosyaya ekliyoruz.
    while ((ch = fgetc(source)) != EOF)
       fputc(ch, target);
    
    printf("DOSYA KOPYALAMA BAŞARILI...\n");
    
    //dosyalar kapatiliyor...
    fclose(source);
    fclose(target);
}

// move_file() fonksiyonu dosya tasima islemi gerceklestirir.
void move_file(char *oldDirectory, char *newDirectory)
{
    // rename fonksiyonu ile dosyayi baska bir dizine tasima
    int re = rename(oldDirectory, newDirectory);

    // rename kontrolu
	if(re == 0)
	{
		printf("DOSYA BASARILI BIR SEKILDE TASINDI...\n");
	
	}
	else
	{
		printf("HATA! DOSYA TASINAMADI. \n");
	}
}

// add_text() fonksiyonu kullanicidan aldigi metni dosya sonuna ekler.
void add_text(char *file_name,char *text_add)
{
    FILE *fp;
    char ch;

    // fopen fonksiyonu olusturmak istedigimiz dosyanin adini uzantisi ile veriyoruz ve "a+"" komutu sayesinde dosyayi okuma ve yazma modunda aciyoruz.
    fp = fopen(file_name, "a+");

    // dosya kontrolu
    if(fp == 0)
    {
        printf("HATAA DOSYA AÇILAMADI..!\n");
    }

    // dosyanin sonuna gidiyoruz
    while (!feof(fp))
    {
        ch = fgetc(fp);
    }


    //int i=0;
    fputs(text_add, fp);
    fclose(fp);
}

// location_add_text() fonksiyonu dosyanin istenilen yerine metin eklemeyi saglar.
void location_add_text(char *file_name, int location, char *new_file_name, char *text_add) 
{
    char ch;
    FILE *source, *target;
    int sayac  = 0;

    // fopen fonksiyonu olusturmak istedigimiz dosyanin adini uzantisi ile veriyoruz ve "r" komutu sayesinde dosyayi okuma modunda acıyoruz.
    source = fopen(file_name, "r");

    // dosya kontrolu
    if (source == NULL) {
       printf("HATALI DOSYA ADI...\n");
       exit(EXIT_FAILURE);
    }
    // fopen fonksiyonu olusturmak istedigimiz dosyanin adini uzantisi ile veriyoruz ve "w" komutu sayesinde dosyayi yazma modunda acıyoruz.
    target = fopen(new_file_name, "w");
    
    // dosya kontrolu
    if (target == NULL) {
       fclose(source);
       printf("HATAA...\n");
       exit(EXIT_FAILURE);
    }
    
    int value = 0;
    // dosyada kullanicinin belirttigi yere text ekleme 
    while ((ch = fgetc(source)) != EOF)
    {
        if(sayac == (location)) 
        {
            fputs(text_add, target);
            sayac++;
        }
        fputc(ch, target);
        sayac++;
    }
    rename(new_file_name, file_name);  
    // dosyalar kapatiliyor
    fclose(source);
    fclose(target);
      
}

// remove_text() fonksiyonu dosyanin icindeki textleri siler.
void remove_text(char *file_name)
{
    FILE *fp;

    // fopen fonksiyonu olusturmak istedigimiz dosyanin adini uzantisi ile veriyoruz ve "w" komutu sayesinde dosyayi yazma modunda acıyoruz.    
    fp = fopen(file_name,"w");

    // dosya kontrolu
    if(fp == 0)
    {
        printf("HATA DOSYA AÇILAMADI \n");
    }
    else
    {
        printf("DOSYANIN İÇİNDEKİ TÜM TEXT BASARI İLE SİLİNDİ.. \n");
    }

    // dosya kapatiliyor
    fclose(fp);

}

// line_display_text() fonksiyonu satir basina duraklatma ozelligi ile bir text dosyasinin icerigini gosterir.
void line_display_text(char *file_name, int location, int begin, int increment)
{
    FILE *fp;

    // fopen fonksiyonu olusturmak istedigimiz dosyanin adini uzantisi ile veriyoruz ve "r" komutu sayesinde dosyayi okuma modunda acıyoruz.
    fp = fopen(file_name,"r");

    // dosya kontrolu
    if(fp == 0)
    {
        printf("HATA DOSYA AÇILAMADI \n");
    }

    char content;
    int counter = 0;

    // print edilecek satirlarin baslangic noktasina ilerleme
    while ((content = fgetc(fp)) != EOF)
    {
        if (counter == begin)
        {
            break;
        }
        else if (content == '\n') counter++;
    }

    // kullanicinin girdigi sayi kadar satiri ekrana yazdiriyor.
    while ((content = fgetc(fp)) != EOF && begin < location)
    {
        if (content == '\n') begin++;
        putchar(content);
    }

    char cmd[255];
    printf("DIGER %d SATIRI GORMEK ISTERSENIZ 1 YOKSA CIKIS YAPMAK ICIN HERHANGI BIR DEGER GIRINIZ: ", increment);

    fgets(cmd, 255, stdin);
    cmd[strcspn(cmd, "\n")] = '\0';

    // kullanici "1" girerse tekrar belirttigi sayida satiri ekrana yazdirir    
    if(!strcmp(cmd, "1"))
    {
        line_display_text(file_name, (location + increment), location, increment);
    }
    else
    {
        printf("CIKIS YAPILDI.\n");
    }
    
}

int main()
{
    char cmd[255];
    char *tokens[20];
    char *text;

    printf("----------------------------------------------------------------------------------------------\n----------------------------------ISU FILEMANAGER HOS GELDINIZ----------------------------------\n----------------------------------------------------------------------------------------------\nAsagidaki komutlari girerek dosya islemleri yapabilirsiniz:\n\n1) create_file = Yeni dosya olusturur.\n2) delete_file = Dosya siler.\n3) rename_file = Dosyayi yeniden adlandirir.\n4) copy_file = Dosyayi baska bir dosyaya kopyalar.\n5) move_file = Dosyayi baska bir dizine tasir.\n6) add_text = Txt dosyalarinin sonuna text ekleme yapar.\n7) location_add_text = Txt dosyasinda belirli konuma text ekleme yapar.\n8) remove_text = Txt dosyasindaki tum texti siler.\n9) line_display_text = txt dosyasindaki girilen deger kadar satir ekrana yazdirir.\n10) exit = Programi sonlandirir.\n\nHELP) Komutlarin nasil kullanildigini gormek icin komut_adi /h yazarak help kismina ulasabilirsiniz\n");

    memset(cmd, 0, 255);

    // kullanici "exit" komutunu girene kadar dongu devam eder. 
    while (strcmp(cmd, "exit")) 
    {
        // read
        char *token;
        fgets(cmd, 255, stdin);
        cmd[strcspn(cmd, "\n")] = '\0'; 
        token = strtok(cmd, " "); // inputu bosluklara gore ayirarak adresini token pointer'ina atiyoruz.

        // token pointer'i adreslerini pointer bir diziye atiyoruz
        for (int i=0; i<20; i++)
        {
            tokens[i] = token;
            token = strtok(NULL, " ");
        }

        // tokens arrayindeki char degiskenini komut ismi ile karsilastirir.
        if (!strcmp(tokens[0], "create_file"))
        {
            // komut kontrolu
            if(tokens[1] == NULL)
            {
               printf("Lutfen komutu dogru girdiginizden emin olunuz.\n");
            }
            
            // help ozelligi
            else if(!strcmp(tokens[1], "/h"))
            {
                printf("----------------------------create_file help----------------------------\n'komut_adi' bosluk birakarak uzantisiyla beraber 'dosya adi' giriniz.\nOrnek olarak: 'create_file metin.txt' \n");
            }
            //Help kontrolu
            else if(!strcmp(tokens[1], "/H"))
            {
                printf("Lutfen komutu dogru girdiginizden emin olunuz.\n");
            }
            else
            {
                create_file(tokens[1]);
            }
        }

        // tokens arrayindeki char degiskenini komut ismi ile karsilastirir.
        else if (!strcmp(tokens[0], "delete_file"))
        {
            // help ozelligi
            if (tokens[1] == NULL)
            {
                printf("Lutfen komutu dogru girdiginizden emin olunuz.\n");
            }
            else if(!strcmp(tokens[1], "/h"))
            {
                printf("----------------------------delete_file help----------------------------\n'komut_adi' bosluk birakarak uzantisiyla beraber 'dosya adi' giriniz.\nOrnek olarak: 'delete_file metin.txt' \n");
            }
            //Help kontrolu
            else if(!strcmp(tokens[1], "/H"))
            {
                printf("Lutfen komutu dogru girdiginizden emin olunuz.\n");
            }
            else 
            { 
                delete_file(tokens[1]);   
            }
        }

        // tokens arrayindeki char degiskenini komut ismi ile karsilastirir.
        else if (!strcmp(tokens[0], "rename_file"))
        {
            // komut kontrolu
            if(tokens[1] == NULL)
            {
                printf("Lutfen komutu dogru girdiginizden emin olunuz.\n");
            }
            // help ozelligi
            else if(!strcmp(tokens[1], "/h"))
            {
                printf("----------------------------rename_file help----------------------------\n'komut_adi' bosluk birakarak uzantisiyla beraber 'dosya adi' ve bosluk birakarak uzantisiyle 'yeni dosya adi' giriniz.\nOrnek olarak: 'rename_file metin.txt yeni_metin.txt' \n");
            }
            // komut kontrolu
            else if (tokens[2] == NULL)
            {
                printf("Lutfen komutu dogru girdiginizden emin olunuz.\n");
            }
            else
            {    
                rename_file(tokens[1], tokens[2]);                    
            }
        }

        // tokens arrayindeki char degiskenini komut ismi ile karsilastirir.
        else if (!strcmp(tokens[0], "copy_file"))
        {
            // komut kontrolu
            if(tokens[1] == NULL)
            {
                printf("Lutfen komutu dogru girdiginizden emin olunuz.\n");
            }
            // help ozelligi
            else if(!strcmp(tokens[1], "/h"))
            {
                printf("----------------------------copy_file help----------------------------\n'komut_adi' bosluk birakarak uzantisiyla beraber kopyasini olusturmak istediginiz 'dosya adi' ve bosluk birakarak kopyalanacak 'dosyanin adi'ni'  giriniz.\nOrnek olarak: 'copy_file metin.txt yeni_metin.txt' \n");
            }
            // komut kontrolu
            else if (tokens[2] == NULL)
            {
                printf("Lutfen komutu dogru girdiginizden emin olunuz.\n");
            }
            else
            {
                file_copying(tokens[1], tokens[2]);
            }
        }

        // tokens arrayindeki char degiskenini komut ismi ile karsilastirir.
        else if (!strcmp(tokens[0], "move_file"))
        {
            // komut kontrolu
            if(tokens[1] == NULL)
            {
                printf("Lutfen komutu dogru girdiginizden emin olunuz.\n");
            }
            // help ozelligi
            else if(!strcmp(tokens[1], "/h"))
            {
               printf("----------------------------move_file help----------------------------\n'komut_adi' bosluk birakarak path ve uzantisiyla beraber 'dosya adi' ve bosluk  birakarak yeni path 'dosya adi' giriniz.\nOrnek olarak: 'move_file path/metin.txt metin.txt' \n");
            }
            // komut kontrolu
            else if (tokens[2] == NULL)
            {
                printf("Lutfen komutu dogru girdiginizden emin olunuz.\n");
            }
            else
            {
                move_file(tokens[1], tokens[2]);
            }
        }

        // tokens arrayindeki char degiskenini komut ismi ile karsilastirir.
        else if (!strcmp(tokens[0], "add_text"))
        {
            // komut kontrolu
            if(tokens[1] == NULL)
            {
                printf("Lutfen komutu dogru girdiginizden emin olunuz.\n");
            }
            // help ozelligi
            else if(!strcmp(tokens[1], "/h"))
            {
                printf("----------------------------add_text help----------------------------\n'komut_adi' bosluk birakarak uzantisiyla beraber 'dosya adi' ve bosluk birakarak eklemek istediginiz 'text'i' giriniz.\nOrnek olarak: 'add_text metin.txt Mevlut Yasar.' \n");
            }
            // komut kontrolu
            else if (tokens[2] == NULL)
            {
                printf("Lutfen komutu dogru girdiginizden emin olunuz.\n");
            }
            else
            {       
                int i = 2;   
                    
                // tokens'in elemani NULL olana kadar tokens'e girilen elamanlarini text pointer'ina yazar ve add_text fonksiyonunu cagirir.      
                while(tokens[i] != NULL)
                {
                    text = *(tokens + i);
                    i++;
                    add_text(tokens[1], text);
                }
                printf("DOSYA ICINE YAZMA BASARILI.\n");   
            }
        }

        // tokens arrayindeki char degiskenini komut ismi ile karsilastirir.
        else if (!strcmp(tokens[0], "remove_text"))
        {
            // komut kontrolu
            if(tokens[1] == NULL)
            {
                printf("Lutfen komutu dogru girdiginizden emin olunuz.\n");
            }
            // help ozelligi
            else if(!strcmp(tokens[1], "/h"))
            {
                printf("----------------------------remove_text help----------------------------\n'komut_adi' bosluk birakarak uzantisiyla beraber 'dosya adi' giriniz.\nOrnek olarak: 'remove_file metin.txt' \n");
            }
            //Help kontrolu
            else if(!strcmp(tokens[1], "/H"))
            {
                printf("Lutfen komutu dogru girdiginizden emin olunuz.\n");
            }
            else
            {
                remove_text(tokens[1]);    
            }
        }

        // tokens arrayindeki char degiskenini komut ismi ile karsilastirir.
        else if (!strcmp(tokens[0], "location_add_text"))
        {
            // komut kontrolu
            if (tokens[1] == NULL)
            {
                printf("Lutfen komutu dogru girdiginizden emin olunuz.\n");
            }
            // help ozelligi
            else if(!strcmp(tokens[1], "/h"))
            {
               printf("----------------------------location_add_text help----------------------------\n'komut_adi' bosluk birakarak uzantisiyla beraber 'dosya adi', eklemek istediğiniz lokasyonu (karakter sayisi olarak), eklemek istediginiz text'i' giriniz.\nOrnek olarak: 'location_add_text metin.txt 20 Dogukan Nadir.' \n");
            }
            // komut kontrolu
            else if(tokens[2] == NULL && tokens[3] == NULL)
            {
                printf("Lutfen komutu dogru girdiginizden emin olunuz.\n");
            }
            else
            {
                int location = 0;
                int counter = 0;
                sscanf(tokens[2], "%d", &location); // string girilen degeri integer'a ceviriyoruz.

                int i = 3;
                // tokens'in elemani NULL olana kadar tokens'e girilen elamanlarini text pointer'ina yazar ve location_add_text fonksiyonunu cagirir.         
                while(tokens[i] != NULL)
                {
                    text = *(tokens + i);
                    i++;
                    location_add_text(tokens[1], (location + counter), "a.txt", text);
                    counter += strlen(text);
                }
                printf("BELIRTILEN LOKASYONA EKLEME BASARILI.\n");  
            }
        }

        // tokens arrayindeki char degiskenini komut ismi ile karsilastirir.
        else if(!strcmp(cmd, "line_display_text"))
        {
            // komut kontrolu
            if(tokens[1] == NULL)
            {
                printf("Lutfen komutu dogru girdiginizden emin olunuz.\n");
            }
            // help ozelligi
            else if(!strcmp(tokens[1], "/h"))
            {
                printf("----------------------------line_display_text help----------------------------\n'komut_adi' bosluk birakarak uzantisiyla beraber 'dosya adi', kac tane satir ekrana yazdirmak istiyorsaniz integer bir deger giriniz.\nOrnek olarak: 'line_display_text metin.txt 10 ' \n");
            }
            else if(tokens[2] == NULL)
            {
                printf("Lutfen komutu dogru girdiginizden emin olunuz.\n");
            }
            else
            {
                int location = 0;
                int begin = 0;
                sscanf(tokens[2], "%d", &location);
                int increment = location;
                line_display_text(tokens[1], location, begin, increment);
            }
        }

        // kullanici "exit" komutunu girerse program sonlanir.
        else if(!strcmp(tokens[0], "exit"))
        {
            break;
        }

        // kullanicin hatali giris yapmasi durumu
        else
        {
            printf("HATALI GIRIS YAPTINIZ TEKRAR DENEYINIZ.\n");
        }
        
    }

    printf("Exiting the command line.\n");
    return 0;

}

