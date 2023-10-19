#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <string>
#include <conio.h>
using namespace std;
struct Song
{
	string path; // duong dan 
	string name;// Ten bai hat
	string artist; // Ten ca si the hien bai hat
	int solangnghe; // Solan nghe 
};
struct NodeSong
{
	Song data;
	NodeSong* next;
	NodeSong* pre;
};
struct ListSong
{
	NodeSong* head;
	NodeSong* tail;
};
// Song
Song createSong(string path, string name, string artist)
{
	Song p;
	p.path = path;
	p.name = name;
	p.artist = artist;
	p.solangnghe = 0;
	return p;
}
NodeSong* createNodeSong(Song s)
{
	NodeSong* p = new NodeSong;
	if (p == NULL)
		return NULL;
	else
	{
		p->data = s;
		p->next = NULL;
		p->pre = NULL;
		return p;
	}
}
void initListSong(ListSong& list)
{
	list.head = NULL;
	list.tail = NULL;
}
void addLastListMusic(ListSong& list, NodeSong* p)
{
	if (list.head == NULL)
	{
		// Luc nay list chi co mot node 
		list.head = list.tail = p;
		list.head->next = list.head;
		list.head->pre = list.head;
	}
	else
	{
		list.tail->next = p;
		p->pre = list.tail;
		p->next = list.head;
		list.head->pre = p;
		list.tail = p;
	}
}
void duyetListSong(ListSong list)
{
	if (list.head == NULL)
	{
		cout << "Album rong \n";
	}
	else
	{
		for (NodeSong* p = list.head; p != NULL; p = p->next)
		{
			cout << "Ten bai: " << p->data.name << "\n";
		}
	}
}
//Thêm
void chuanHoaDuongDan(string& s)
{

}
void themBaiHatUser(ListSong &myMusic)
{
	string duongDan;
	string tenBaiHat; 
	string tenTacGia;
	cout << "Nhap duong dan de them bai hat: \n";
	getline(cin, duongDan);
	cout << "Nhap ten bai hat: \n";
	getline(cin, tenBaiHat);
	cout << "Nhap ten tac gia: \n";
	getline(cin, tenTacGia);

	Song song1 = createSong(duongDan, tenBaiHat,tenTacGia);
	NodeSong* node1 = createNodeSong(song1);
	if (node1 != NULL)
	{
		addLastListMusic(myMusic,node1);
		cout << "Bai hat" << tenBaiHat << " duoc them thanh cong!!!\n";
	}
}
void themBaiHatAdmin(ListSong& myMusic,string duongDan, string tenBaiHat, string tenTacGia)
{
	Song song = createSong(duongDan, tenBaiHat, tenTacGia);
	NodeSong* node = createNodeSong(song);
	if (node != NULL)
	{
		addLastListMusic(myMusic, node);
	}
}
//Play music
void PlaySong(Song s)
{
	wstring widestr = wstring(s.path.begin(), s.path.end());
	const wchar_t* path = widestr.c_str();
	int n;
	while (true)
	{
		PlaySound(path, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		cin >> n;
		if (n == 0)
			break;

	}
}
void PlayListMusic(ListSong list)
{
	if (list.head == NULL)
		cout << "Danh sach rong \n";
	else
	{
		char directAlbum;
		NodeSong* p = list.head;
		while (true)
		{
			system("cls");
			cout << "-----Ban dang nghe bai hat:" << p->data.name<<" "<<p->data.artist<< "-------\n";
			cout << "Neu muon dung hay nhap s \n";
			cout << "Neu ban muon nghe bai hat tiep theo hay nhap d \n";
			cout << "Neu ban muon nghe bai hat truoc hay nhap a \n";

			wstring widestr = wstring(p->data.path.begin(), p->data.path.end());
			const wchar_t* path = widestr.c_str();
			PlaySound(path, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			cin >> directAlbum;
			if (directAlbum == 's')
			{
				PlaySound(0, 0, 0);
				break;
			}
			else if (directAlbum == 'd')
			{
				PlaySound(0, 0, 0);
				p = p->next;
			}
			else if (directAlbum == 'a')
			{
				PlaySound(0, 0, 0);
				p = p->pre;
			}
		}
	}
}
int main()
{
	ListSong myMusic;
	initListSong(myMusic);
	// Them cac bai hat vao mot list co san 
	themBaiHatAdmin(myMusic, "kisstherain", "Kiss the rain", "Yimura");
	themBaiHatAdmin(myMusic, "bandoi", "Ban doi", "Karik ft Gducky");
	themBaiHatAdmin(myMusic, "canonind", "Canon in d", "");
	themBaiHatAdmin(myMusic, "nangtho", "Nang tho", "Hoang Dung");
	themBaiHatAdmin(myMusic, "riverflowinyou", "River flow in you", "Yimura");
	themBaiHatAdmin(myMusic, "thangtulaloinoidoicuaem", "Thang tu la loi noi doi cua em", "Ha Anh Tuan");
	themBaiHatAdmin(myMusic, "tusu", "Tu su", "Orange");
	themBaiHatAdmin(myMusic, "xinloi", "Xin loi", "Thang ngot");
	PlayListMusic(myMusic);
	// kiem tra duong dan, da lam duoc tinh nang them bai nhac 
}

