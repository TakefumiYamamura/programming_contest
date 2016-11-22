#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Section
{
	int l;
	int r;
};

struct Migration
{
	int start;
	int end;
};

class GreatMigration
{
public:
	int n, d, k;
	vector<Section> sections;
	vector<Migration> migrations;
	GreatMigration();
	~GreatMigration();
	int bruteForthSearch(Migration mgr);
	void exec();
	
};

GreatMigration::GreatMigration(){
	cin >> n >> d >> k;
	for (int i = 0; i < d; ++i)
	{
		Section tmp;
		cin >> tmp.l >> tmp.r;
		sections.push_back(tmp);
	}

	for (int i = 0; i < k; ++i)
	{
		Migration tmp;
		cin >> tmp.start >> tmp.end;
		migrations.push_back(tmp);
	}
}

GreatMigration::~GreatMigration(){}

int GreatMigration::bruteForthSearch(Migration mgr){
	int cur_r = mgr.start;
	int cur_l = mgr.start;
	if(mgr.start < mgr.end){
		for (int i = 0; i < sections.size(); ++i)
		{
			if(sections[i].l <= cur_r && cur_r <= sections[i].r){
				cur_r = sections[i].r;
			}
			if(cur_r >= mgr.end){
				return i+1;
			}
		}
	}else{
		for (int i = 0; i < sections.size(); ++i)
		{
			if(cur_l <= sections[i].r && sections[i].l <= cur_l){
				cur_l = sections[i].l;
			}
			if(cur_l <= mgr.end){
				return i+1;
			}

		}

	}
	return -1;
}

void GreatMigration::exec(){
	for (int i = 0; i < migrations.size(); ++i)
	{
		cout << bruteForthSearch(migrations[i]) << endl;
	}
}

int main(){
	GreatMigration gm = GreatMigration();
	gm.exec();

}
