#include <fstream>
#include <iostream>


struct Record{
	uint64_t next;
	char data[504];
};

void printRecord(int index,const Record& record, std::ostream&os){
	os<<index<<" "<<"next:"<<record.next<<" "<<record.data<<std::endl;
}

void print(std::ostream& os, const char* fileName){
	
	std::ifstream ifs(fileName, std::ios::binary);
	
	if(!ifs){
		return;
	}
	
	int currentIndex=0;
	while(true){
		Record currentRecord;
		ifs.seekg(currentIndex*sizeof(Record));
		ifs.read((char*)&currentRecord,sizeof(Record));
		printRecord(currentIndex,currentRecord,os);
		if(currentRecord.next==0){
			break;
		}
		currentIndex=currentRecord.next;
	}
	
	ifs.close();
}

int main(){
	
	
	const char* file="maintasks.dat";
	print(std::cout,file);
}