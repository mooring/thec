#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#define P1  "curl "
#define P2  "%s%04d%s"
#define P4  "authority: ia600902.us.archive.org"
#define P40 "accept: image/webp,image/apng,image/svg+xml,image/*,*/*;q=0.8"
#define P41 "accept-language: zh-CN,zh;q=0.9,en;q=0.8,en-US;q=0.7"
#define P42 "cache-control: no-cache"
#define P43 "pragma: no-cache"
#define P44 "dnt: 1"
#define P5  "cookie: %s"  
#define P6  "referer: %s" 
#define P7  "user-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/110.0.0.0 Safari/537.36 Edg/110.0.1587.50"
#define P8  "%s" 
#define P9  " -o leaf%03d.jpg"

#define PF "\" -H \"" P40 "\" -H \"" P41 "\" -H \"" P42 "\" -H \"" P43 "\" -H \"" P44
#define URL P1 "\"" P2 "\" -H \"" P4 PF "\" -H \"" P5 "\" -H \"" P6 "\" -H \"" P7 "\"" P8 P9

void write2file(int index, int current, int total){
    char str[3000] = {0};
	char *proxy = ""; //  " --proxy \"http://127.0.0.1:15236\"";
	char *prefix = "https://ia601002.us.archive.org/BookReader/BookReaderImages.php?zip=/29/items/draftstandardcli00plau/draftstandardcli00plau_jp2.zip&file=draftstandardcli00plau_jp2/draftstandardcli00plau_";
	char *suffix = ".jp2&id=draftstandardcli00plau&scale=1&rotate=0";
	char *referer = "https://archive.org/details/draftstandardcli00plau/page/495/mode/1up?view=theater";
	
	char *cookie = ""; // change to real cookie

	printf("geting page leaf%03d.jpg ( %d/%d )\n------------------------------\n", index, current, total);
    sprintf(str, URL, prefix, index, suffix, cookie, referer, proxy, index);
	system(str);
	putchar('\n');
	Sleep(10);
}
/*
 * @description download book from archive.org with specify page/range/full
 * @usage get.exe 10/ get.exe 1 10/ get
 * @need to change: 
 *          start: start range
 *          end  : end   range
 *          proxy: keep it empty if noproxy
 */

int main(int argc, char *argv[]){
	int i = 1, j = 0,start = 1, end = 404;
	if(argc == 2){
		start = atoi(argv[1]);
		write2file(start, 1, 1);
	}else{
		if(argc == 3){
			start = atoi(argv[1]);
			end   = atoi(argv[2]);
		}
		for(i=start; i<end+1; i++){
			write2file(i, ++j, end-start+1);
		}
		printf("get range(%d ~ %d) done\n", start, end);
	}
	return 0;
}

