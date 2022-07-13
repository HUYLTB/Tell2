#include <iostream>
class Linklist
{
protected:
	// struct de luu cac kieu cua Student như id va name;
	struct Student1
	{
		std::string name;
		int id;
	};
	// mot Node SV de luu dslk
	struct SV
	{
		Student1 data;
		SV *next;
	};
	typedef struct SV *sv;
	// tao node head
public:
	sv head;
	// khoi tao node head
	Linklist()
	{
		head = NULL;
	}
	sv Creat()
	{ // tao mot node moi theo kieu du lieu student
		Student1 sv1;
		do{		
		std::cout << "Nhap vao ma sinh vien: ";
		std::cin >> sv1.id;
		std::cin.ignore();
		if(Find(sv1.id)) std::cout<<"\nDa ton tai id Student \n";}
		while(Find(sv1.id));
		std::cout << "Nhap vao ten sv: ";
		getline(std::cin, sv1.name);
		sv tmp = new SV();
		tmp->data = sv1;
		tmp->next = NULL;
		return tmp;
	}
	bool Find(int b){//kiem tra ma sinh vien da ton tai chua. nhap lại
		sv a=head;
		while (a != NULL)
		{
			if(a->data.id==b)
			return true;
			a=a->next;
		}
		return false;
	}
	int Size(sv a)
	{ // size cua Node
		int dem = 0;
		while (a != NULL)
		{
			dem++;
			a = a->next;
		}
		return dem;
	}
	bool Empty(sv x)
	{ // kiem tra rong
		return x == NULL;
	}
	void Insert(sv &a)
	{ // chen mot node moi
		sv tmp = Creat();
		if (a == NULL)
		{
			a = tmp;
		}
		else
		{
			tmp->next = a;
			a = tmp;
		}
	}
	// xoa node o vi tri
	void Delete(sv &a, int index)
	{
		if (index <= 0 || index > Size(a))
			return;
		sv p = NULL, q = a;
		for (int i = 1; i < index; i++)
		{
			p = q;
			q = q->next;
		}
		if (p == NULL)
		{
			a = a->next;
		}
		else
		{
			p->next = q->next;
		}
	}
	// duyet in ds student
	void in(Student1 sv1)
	{
		std::cout << "--------------------------------\n";
		std::cout << "ID : " << sv1.id << std::endl;
		std::cout << "Ho ten :" << sv1.name << std::endl;
		std::cout << "--------------------------------\n";
	}
	// duyet in ds Ndoe
	void inds(sv a)
	{
		std::cout << "Danh sach sinh vien :\n";
		while (a != NULL)
		{
			in(a->data);
			a = a->next;
		}
		std::cout << std::endl;
	}
	// tim kiem Student theo ID
	void Checkid(sv a)
	{
		int tmp, dem = 0;
		sv q;
		std::cout << "Nhap ma sinh vien can tim: ";
		std::cin >> tmp;
		std::cin.ignore();
		for (sv p = a; p != NULL; p = p->next)
		{
			if (p->data.id == tmp)
			{
				q = p;
				dem++;
				break;
			}
		}
		if (dem > 0)
		{
			std::cout << "Sinh vien can tiem là";
			in(q->data);
		}
		else
		{
			std::cout << "Sinh vien ko ton tai";
		}
	}
	// tim kiem Student theo ten
	void Checkname(sv a)
	{
		int dem = 0;
		std::string tmp;
		std::cin.ignore();
		std::cout << "Nhap ten sinh vien can tim: ";
		getline(std::cin, tmp);
		std::cout << "\nSinh vien can tim la: \n";
		for (sv p = a; p != NULL; p = p->next)
		{
			if (p->data.name == tmp)
			{
				in(p->data);
				std::cout << std::endl;
				dem++;
			}
		}
		if (dem == 0)
		{
			std::cout << "\nSinh vien ko ton tai\n";
		}
	}
	// xoa id tìm vi tri
	void DeleteID(sv a)
	{
		int tmp, dem = 1, kt = 0;
		sv p = a;
		std::cout << "\nNhap ma sinh vien can tim: ";
		std::cin >> tmp;
		std::cin.ignore();
		while (p != NULL)
		{
			if (p->data.id == tmp)
			{
				kt++;
				break;
			}
			dem = dem + 1;
			p = p->next;
		}
		if (kt > 0)
		{
			std::cout << "\nDanh sach sinh vien sau xoa:\n";
			Delete(a, dem);
			inds(a);
		}
		else
		{
			std::cout << "Sinh vien ko ton tai";
		}
	}
	// BAI 2::::::::::::::::::::
	// xap sep theo kieu BubbeSort bai 2
	void BubbleSort(sv &a)
	{
		sv p;
		sv q;
		Student1 sv1;
		for (p = a; p->next != NULL; p = p->next)
		{
			for (q = p->next; q != NULL; q = q->next)
			{
				if (p->data.id < q->data.id)
				{
					sv1 = p->data;
					p->data = q->data;
					q->data = sv1;
				}
			}
		}
	}
};
int main()
{ // tao cac muc lua chon
	Linklist lk;
	int chon;
	while (true)
	{
		std::cout << "*****LINKED LIST*******\n";
		std::cout << "1. Chen sinh vien vao danh sach\n";
		std::cout << "2. Tim kiem sinh vien theo ma sinh vien\n";
		std::cout << "3. Tim kiem sinh vien theo ten sinh vien\n";
		std::cout << "4. Xoa sinh vien theo ma sinh vien\n";
		std::cout << "5. Sap xep sinh vien theo id\n";
		std::cout << "6. In danh sach sinh vien\n";
		std::cout << "7. Thoat\n";
		std::cout << "Nhap lua chon: ";
		std::cin >> chon;
		std::cin.ignore();
		switch (chon)
		{
		case 1:
			lk.Insert(lk.head);
			break;
		case 2:
			lk.Checkid(lk.head);
			break;
		case 3:
			lk.Checkname(lk.head);
			break;
		case 4:
			lk.DeleteID(lk.head);
			break;
		case 5:
			lk.BubbleSort(lk.head);
			std::cout << "\nDanh sach sau khi sap xep\n";
			lk.inds(lk.head);
			break;
		case 6:
			lk.inds(lk.head);
			break;
		case 7:
			return 0;
		default:
			std::cout << "Nhap lai lua chon: ";
			std::cin >> chon;
			break;
		}
	}
	return 0;
}