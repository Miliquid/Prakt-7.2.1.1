#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <cstdlib>
using namespace std;
const int n=3;
string pr[n] = {"Информатика", "Основы алгоритмизации", "Теория алгоритмов"};
	class Student {
	private:
		string f;
		string i;
		string o; 
		int ed[n];
	public:
		static int kol;
		static int kud;
		static int kneud;
		static float srall;
		
		void setF(string fc)
		{
			f=fc;
		}
		void setI(string ic)
		{
			i=ic;
		}
		void setO(string oc)
		{
			o=oc;
		}
		void setEd(int i,int edc)
		{
			ed[i]=edc;
		}
		
		float sr()
		{
			int sum=0;
			for (int i=0;i<n;i++) sum+=ed[i];
			return sum/3.0;
		}
			
		void srminus ()
		{
			int bol=0;
			cout << "\nПредметы с оценкой ниже средней: ";
			for (int i=0;i<n;i++)
				if (ed[i]<sr())
				{
					cout << "\n\t" << pr[i] << " - " << ed[i];
					bol=1;
				}
			if (bol==0) cout << "отсутствуют"; 
		}
		
		void edmax (int arr[n+1])
		{
			int mx=0;
			for (int i=0;i<n;i++)
			if (ed[mx]<ed[i]) mx=i;
			for (int i=0;i<n;i++)
			if (ed[i]==ed[mx]) arr[i]=1; else arr[i]=0;
			arr[n]=ed[mx];
		}
		
		void inf()
		{
			cout << "\nСтудент: " << f << " " << i << " " << o;
			cout << "\nОценки по трём предметам: ";
			for (int i=0;i<n;i++) cout << " " << ed[i];
			cout << "\nСредняя оценка: " << fixed << setprecision(2) << sr();
		}
		
		void itog()
		{
			cout << "\nКоличество студентов: " << kol;
			cout << "\nКоличество удовлетворительных оценок: " << kud;
			cout << "\nКоличество неудовлетворительных оценок: " << kneud;
			srall=srall/kol;
			cout << "\nОбщая средняя оценка: " << fixed << setprecision(2) << srall;
			
		}
		
		Student (string ff, string ii, string oo, int arr[3])
		{
			f=ff;
			i=ii;
			o=oo;
			for(int j=0;j<n;j++) 
			{
				ed[j]=arr[j]; 
				if (ed[j]==2) kneud++; else kud++; 
			}
			kol++;
			srall+=sr();
		} 
		Student (){}
		~Student()
		{
			kol--;
			for (int i=0;i<n;i++)
			if (ed[i]==2) kneud--; else kud--;
			srall-=sr();
		}
	};
	
	void vvod(Student *s)
	{
		cout << "\nВведите фамилию студента ";
		string fc,ic,oc;
		cin >> fc;
		s->setF(fc);
		cout << "Введите имя студента ";
		cin >> ic;
		s->setI(ic);
		cout << "Введите отчество студента ";
		cin >> oc;
		s->setO(oc);
		cout << "Введите оценки по " << n << " предметам" ;
		for (int i=0;i<n;i++) 
		{
			int edc; 
			cin >> edc; 
			if ((edc<2||edc>5)) {cout << "Неверный ввод"; exit(0);} 
			if (edc==2) s->kneud++; else s->kud++;
			s->setEd(i,edc); 
		}
		Student::kol++;
		Student::srall+=s->sr();
	}
	
	int Student::kol=0;
	int Student::kud=0;
	int Student::kneud=0;
	float Student::srall=0;
		
	int main() 
	{
		
		int resu[n+1];
		
		int m=30;
		cout << "Введите информацию о студентах (не более " << m<< ")";
		Student *students = new Student[m];
		
		for (int j=0;j<m;j++)
		{	
			cout << "\n\nСтудент №" << j+1;	
			vvod(&students[j]);
			students[j].inf();
			students[j].srminus();
			students[j].edmax(resu);
			cout << "\nМаксимальная оценка по предмету: " << resu[n] << " - ";
			for (int i=0;i<n;i++)
			if (resu[i]==1) cout << pr[i] << ";";
			int que;
			cout << "\n\n\nВвести информацию о новом студенте? (0-нет,1-да)";
			cin >> que;
			if (que==0) break;
		}
		students[0].itog();
		
		return 0;
	}

