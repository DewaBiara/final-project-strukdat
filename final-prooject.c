void BuatAkun(){
	Biodata Pembeli;
	PEMBELI=fopen("pengunjung.txt","a+");
	printf("Nama \t\t\t: "); scanf("%[^\n]",&Pembeli.nama); fflush(stdin);
	printf("Username \t\t: "); scanf("%[^\n]",&Pembeli.username); fflush(stdin);
	printf("Umur \t\t\t: "); scanf("%i",&Pembeli.umur); fflush(stdin);
	printf("No Telepon \t\t: "); scanf("%[^\n]",&Pembeli.telepon); fflush(stdin);
	printf("Nama Sekolah/Instansi \t: "); scanf("%[^\n]",&Pembeli.pendidikan); fflush(stdin);
	printf("Password \t\t: "); scanf("%[^\n]",&Pembeli.password); fflush(stdin);
	printf("Tunggu Sebentar...\n");
	fprintf(PEMBELI,"%s_%s_%i_%s_%s_%s\n", Pembeli.nama, Pembeli.username, Pembeli.umur, Pembeli.telepon, Pembeli.pendidikan, Pembeli.password);
	printf("Selamat! Akun Anda sudah berhasil dibuat.\n");
	fclose(PEMBELI);
}

int Login(){
	char user[20], pass[20];
	Biodata Pembeli;
	PEMBELI=fopen("pembeli.txt","r");
    printf("Username : "); scanf("%s",&user); fflush(stdin);
    printf("Password : "); scanf("%s",&pass); fflush(stdin);
	while (!feof(PEMBELI)){
		fscanf(PEMBELI,"%[^_]_%[^_]_%i_%[^_]_%[^_]_%[^\n]\n",&Pembeli.nama, &Pembeli.username, &Pembeli.umur, &Pembeli.telepon, &Pembeli.pendidikan, &Pembeli.password);
		fflush(stdin);
		if(strcmp(user,Pembeli.username)==0 && strcmp(pass,Pembeli.password)== 0) {
			system("cls");
			return 1;;
		}
	}
}

