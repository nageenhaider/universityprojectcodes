#include<iostream>
#include<fstream>
#include<string>
#include <vector>  
#include <sstream>
#include <stdlib.h>
using namespace std;



class name {
	char* fname;
	char* lname;

public:
	name(char* fn, char* ln) {
		int len = strlen(fn);
		int len1 = strlen(ln);
		fname = new char[len + 1];
		lname = new char[len1 + 1];

		for (int i = 0; i < len + 1; i++)
		{
			fname[i] = fn[i];
		}
		for (int i = 0; i < len1 + 1; i++)
		{
			lname[i] = ln[i];
		}
	}

	name() {

		fname = new char[30];
		lname = new char[30];

		fname = nullptr;
		lname = nullptr;

	}

	void setf(char* fn) {
		int len = strlen(fn);
		fname = new char[len + 1];
		for (int i = 0; i < len + 1; i++)
		{
			fname[i] = fn[i];
		}

	}

	void setl(char* ln) {
		int len1 = strlen(ln);
		lname = new char[len1 + 1];
		for (int i = 0; i < len1 + 1; i++)
		{
			lname[i] = ln[i];
		}
	}

	char* getf() {

		return fname;
	}

	char* getl() {

		return lname;
	}


	name(const name& obj) {
		fname = obj.fname;
		lname = obj.lname;
		//return obj;
	}





	friend ostream& operator<<(ostream& out, const name& obj) {
		out << obj.fname << " " << obj.lname << endl;
		return out;

	}
	//destructor add karo
	~name() {
		//delete[]fname;
		//delete[]lname;
	}
};

class date {
	int dat;
	int month;
	int year;

public:
	date() {
		dat = 0;
		month = 0;
		year = 0;

	}
	date(int a, int b, int c) {
		dat = a;
		month = b;
		year = c;


	}
	void setdate(int a) {

		dat = a;
	}
	void setmonth(int a) {
		month = a;
	}
	void setyear(int a) {
		year = a;
	}

	int getdate() {
		return dat;
	}
	int getmonth() {
		return month;
	}
	int getyear() {
		return year;
	}
	friend ostream& operator<<(ostream& out, const date& obj1) {
		out << obj1.dat << ", " << obj1.month << ", " << obj1.year;

		return out;

	}
	date operator=(const date& obj) {
		dat = obj.dat;
		month = obj.month;
		year = obj.year;
		return obj;
	}
};

class mtime {
	int hrs;
	int mins;
	int secs;

public:
	mtime() {
		hrs = 0;
		mins = 0;
		secs = 0;

	}
	mtime(int a, int b, int c) {
		hrs = a;
		mins = b;
		secs = c;


	}
	void sethr(int a) {

		hrs = a;
	}
	void setmins(int a) {
		mins = a;
	}
	void setsec(int a) {
		secs = a;
	}

	int gethrs() {
		return hrs;
	}
	int getmins() {
		return mins;
	}
	int getsecs() {
		return secs;
	}
	friend ostream& operator<<(ostream& out, const mtime& obj) {
		out << obj.hrs << ":" << obj.mins << ":" << obj.secs;
		return out;

	}

};

class service {
	char* source;
	char* destination;

	float distance;
	mtime bookingtime;
	date bookingdate;
	bool status; // 0 = not  completed  || 1 = completed 

	float fuelrate;
	int CI;

	int DI;
	int VI;

public:

	service() {
		source = new char[100];
		source = nullptr;

		destination = new char[100];
		destination = nullptr;

		distance = 0;
		status = true;
		fuelrate = 0;
		CI = 0;
		DI = 0;
		VI = 0;

	}

	service(char* a, char* b, float c, bool d, float e, int ci, int di, int vi, int da, int mo, int ye, int h, int mi, int se) {

		int len = strlen(b);
		destination = new char[len + 1];
		for (int i = 0; i < len + 1; i++)
		{
			destination[i] = b[i];
		}
		int len1 = strlen(a);
		source = new char[len + 1];
		for (int i = 0; i < len + 1; i++)
		{
			source[i] = a[i];
		}
		//source = new char[100];
		//source = a;
		//destination = new char[100];
		//destination = b;
		distance = c;
		status = d;
		fuelrate = e;
		CI = ci;
		DI = di;
		VI = vi;
		//booking(da, mo, ye);
		bookingdate.setdate(da);
		bookingdate.setmonth(mo);
		bookingdate.setyear(ye);

		bookingtime.sethr(h);
		bookingtime.setmins(mi);
		bookingtime.setsec(se);

		bookingdate.getdate();
		bookingdate.getmonth();
		bookingdate.getyear();

		bookingtime.gethrs();
		bookingtime.getmins();
		bookingtime.getsecs();

	}



	service(const service& a) {
		source = a.source;
		destination = a.destination;
		distance = a.distance;
		status = a.status;
		fuelrate = a.fuelrate;
		CI = a.CI;;
		DI = a.DI;;
		VI = a.VI;
		//booking(da, mo, ye);
		bookingdate = a.bookingdate;
		bookingtime = a.bookingtime;


	}


	void setserdate(date a) {
		bookingdate = a;

	}
	date getserdate() { return bookingdate; }

	void setsertime(mtime a) {
		bookingtime = a;

	}
	mtime getsertime() { return bookingtime; }

	void setdestination(char* des) {
		int len = strlen(des);
		destination = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			destination[i] = des[i];
		}
		destination[len] = '\0';
	}
	void setsource(char* s) {
		int len = strlen(s);
		source = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			source[i] = s[i];
		}
		source[len] = '\0';
	}

	char* getdestination() {

		return destination;
	}

	char* getsource() {

		return source;
	}

	void setdistance(float a) {
		distance = a;
	}
	void setfulerate(float a) {
		fuelrate = a;
	}

	float getdistance() {
		return distance;
	}
	float getfuelrate() {
		return fuelrate;
	}

	void setci(int a) {

		CI = a;
	}
	void setdi(int a1) {
		DI = a1;
	}
	void setvi(int a11) {
		VI = a11;
	}

	int getci() {
		return CI;
	}
	int getdi() {
		return DI;
	}
	int getvi() {
		return VI;
	}

	void setstatus(bool a) {
		status = a;
	}
	bool getstatus() {
		return status;
	}


	friend ostream& operator<<(ostream& out, const service& obj) {
		//out << obj.hrs << ":" << obj.mins << ":" << obj.secs << endl;
		//out << obj.bookingdate << " " << obj.bookingtime << " " << obj.destination << " " << obj.source;
		out << "source = " << obj.source << endl;
		out << "destination = " << obj.destination << endl;
		out << "date = " << obj.bookingdate << endl;
		out << "time = " << obj.bookingtime << endl;
		out << "distance = " << obj.distance << endl;
		out << "fuelrate = " << obj.fuelrate << endl;
		out << "customer ID = " << obj.CI;
		return out;

	}

	//service(const service& a)

	~service() {

		//delete[] source;
		//delete[] destination;
	}
};

struct ser {
	char* source;
	char* destination;

	float distance;
	mtime bookingtime;
	date bookingdate;
	bool status;

	float fuelrate;
	int CI;

	int DI;
	int VI;
	ser() {
		source = new char[100];
		source = nullptr;

		destination = new char[100];
		destination = nullptr;

		distance = 0;
		status = true;
		fuelrate = 0;
		CI = 0;
		DI = 0;
		VI = 0;

	}

	ser(char* a, char* b, float c, bool d, float e, int ci, int di, int vi, int da, int mo, int ye, int h, int mi, int se) {
		source = new char[100];
		destination = new char[100];
		distance = c;
		status = d;
		fuelrate = e;
		CI = ci;
		DI = di;
		VI = vi;
		//booking(da, mo, ye);
		bookingdate.setdate(da);
		bookingdate.setmonth(mo);
		bookingdate.setyear(ye);

		bookingtime.sethr(h);
		bookingtime.setmins(mi);
		bookingtime.setsec(se);

		bookingdate.getdate();
		bookingdate.getmonth();
		bookingdate.getyear();

		bookingtime.gethrs();
		bookingtime.getmins();
		bookingtime.getsecs();

	}



};


class ride :public service {
	int noofpassengers;

	char* ridetype;

	float driverrank;

	float vehiclerank;
	//ser a;
	service a;

	int ff;//1 means free,2 means booked,3 cancelled

public:

	ride() {
		noofpassengers = 0;
		ridetype = new char[100];
		ridetype = nullptr;
		driverrank = 0;
		vehiclerank = 0;
		ff = 0;
	}

	ride(char* a, char* b, float c, bool d, float e, int ci, int di, int vi, int da, int mo, int ye, int h, int mi, int se, int pass, char* ri, float dr, float vr) :service(a, b, c, d, e, ci, di, vi, da, mo, ye, h, mi, se) {

		noofpassengers = pass;
		driverrank = dr;
		vehiclerank = vr;
		int len = strlen(ri);
		ridetype = new char[len + 1];
		for (int i = 0; i < len + 1; i++)
		{
			ridetype[i] = ri[i];
		}

	}

	//ride(int pass, char* ri, float dr, float vr, ser b) {

	//	noofpassengers = pass;
	//	driverrank = dr;
	//	vehiclerank = vr;
	//	int len = strlen(ri);
	//	ridetype = new char[len + 1];
	//	for (int i = 0; i < len + 1; i++)
	//	{
	//		ridetype[i] = ri[i];
	//	}
	//	//a = b;

	//}

	void setpassengers(int a) {

		noofpassengers = a;
	}
	void setff(int a) {

		ff = a;
	}
	void setdriverrank(float a) {

		driverrank = a;
	}
	void setvehiclerank(float b) {

		vehiclerank = b;
	}

	void setridetype(char* ri) {
		int len = strlen(ri);
		ridetype = new char[len + 1];
		for (int i = 0; i < len + 1; i++)
		{
			ridetype[i] = ri[i];
		}
	}
	void setservice(service b) {

		a = b;
	}
	int getpassensgers() {
		return noofpassengers;
	}
	int getff() {
		return ff;
	}

	float getdriverank() {
		return driverrank;
	}
	float getvehicleank() {
		return vehiclerank;

	}
	char* getridetype() {
		return ridetype;
	}
	service getservice() {
		return a;
	}
	//add destructor

	friend ostream& operator<<(ostream& out, const ride& obj) {
		//out << obj.hrs << ":" << obj.mins << ":" << obj.secs << endl;
		//out << obj.bookingdate << " " << obj.bookingtime << " " << obj.destination << " " << obj.source;
		out << obj.a;
		out << "number of passengers = " << obj.noofpassengers << endl;
		out << "ride type = " << obj.ridetype << endl;
		out << "driver rank = " << obj.driverrank << endl;
		out << "vehicle rank = " << obj.vehiclerank << endl;
		cout << endl;
		return out;

	}
	~ride() {
		//delete[] ridetype;
	}
};

class delivery : public service {
private:

	float goodweight;
	char* ggoodstype;
	//ser o;
	float driverrank;

	float vehiclerank;
	service c;
	int ff;//1 means free,2 means booked,3 cancelled
public:
	delivery()
	{
		goodweight = 0;
		ggoodstype = new char[100];
		ggoodstype = nullptr;
		driverrank = 0;
		vehiclerank = 0;
		ff = 0;
	}
	void setff(int a) {

		ff = a;
	}
	int getff() {
		return ff;
	}
	/*delivery(int a, char* b, ser i)
	{
		o = i;

		int len = strlen(b);
		goodstype = new char[len + 1];
		for (int i = 0; i < len + 1; i++)
		{
			goodstype[i] = b[i];

		}
		goodweight = a;

	}*/
	/*delivery(char* a, char* b, float c, bool d, float e, int ci, int di, int vi, int da, int mo, int ye, int h, int mi, int se, int pass, char* gt, float gw) :service(a, b, c, d, e, ci, di, vi, da, mo, ye, h, mi, se)
	{

		goodweight = gw;
		int len = strlen(gt);
		ggoodstype = new char[len + 1];
		for (int i = 0; i < len + 1; i++)
		{
			ggoodstype[i] = gt[i];
		}

	}*/
	//ADD SETTERS AND GETTERS
	void setservice(service b) {

		c = b;

	}
	service getservice() {
		return c;
	}
	void setgoodweight(float a) {
		goodweight = a;
	}

	float getdriverank() {
		return driverrank;
	}
	float getvehicleank() {
		return vehiclerank;

	}
	void setgoodstype(char* gx) {

		int len = strlen(gx);
		ggoodstype = new char[len + 1];

		for (int i = 0; i < len + 1; ++i)
		{
			ggoodstype[i] = gx[i];

			//gt[i] = goodstype[i];
		}

	}
	void setdriverrank(float a) {

		driverrank = a;
	}
	void setvehiclerank(float a) {

		vehiclerank = a;
	}

	char* getgoodstype() {
		return ggoodstype;
	}
	float getgoodsweight() {
		return goodweight;
	}



	friend ostream& operator<<(ostream& out, const delivery& obj) {
		//out << obj.hrs << ":" << obj.mins << ":" << obj.secs << endl;
		//out << obj.bookingdate << " " << obj.bookingtime << " " << obj.destination << " " << obj.source;
		out << obj.c << endl;
		out << "goodsweight = " << obj.goodweight << endl;
		out << "goodtype = " << obj.ggoodstype << endl;
		out << "driver rank = " << obj.driverrank << endl;
		out << "vehicle rank = " << obj.vehiclerank << endl << endl;;

		return out;

	}
	~delivery() {
		//delete[] ggoodstype;
	}
};

class person {
private:
	name pname;
	date pdate;
	int age;
	int nid;
public:
	person() {
		age = 0;
		nid = 0;
	}
	person(int ag, int id, name pn, date da) {

		age = ag;
		nid = id;
		pname.setf(pn.getf());
		pname.setl(pn.getl());
		pname.getf();
		pname.getl();
		pdate = da;

	}
	void setage(int agee) {

		age = agee;
	}

	void setpid(int id) {
		nid = id;
	}
	void setpDate(date b) {
		//pdate = b;
		pdate.setdate(b.getdate());
		pdate.setmonth(b.getmonth());
		pdate.setyear(b.getyear());
	}
	void setpName(name b) {
		//pname = b;
		pname.setf(b.getf());
		pname.setl(b.getl());

	}
	person(const person& obj) {
		age = obj.age;
		nid = obj.nid;
		pname = obj.pname;
		pdate = obj.pdate;
	}
	int getpid() {
		return nid;
	}
	date getpDate() {
		return pdate;
	}

	name getpName() {
		return pname;
	}
	int getage() {
		return age;
	}
	/*person operator =(const person& obj) {
		age = obj.age;
		nid = obj.nid;
		pname = obj.pname;
		pdate = obj.pdate;
		return obj;
	}*/



	friend ostream& operator<<(ostream& out, const person& obj) {
		//out << obj.fname << " " << obj.lname << endl;
		out << "name= " << obj.pname;
		out << "date of birth= " << obj.pdate << endl;
		out << "age= " << obj.age << endl << "person id " << obj.nid << endl;

		return out;

	}
virtual	void print()
     {
		cout << pname;
		cout << "date of birth=" << pdate;
		cout << "age = "<<age;
		//cout<<""


	 }

   ~person()
   {

   }
};

class customer :public person {
private:

	int cid;
	service** bookinghistory;
	person a1;
public:
	customer() {
		cid = 0;
		bookinghistory = new service * [1];
		for (int i = 0; i < 1; i++)
		{
			bookinghistory[i] = new service[100];
		}


		bookinghistory = 0;



	}

	//parameterized constructor
	customer(int id, person b, service** a) {

		cid = id;
		bookinghistory = new service * [20];
		for (int i = 0; i < 1; i++)
		{
			bookinghistory[i] = new service[100];
		}

		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				bookinghistory[i][j] = a[i][j];
			}
		}


		a1 = b;


	}


	friend ostream& operator<<(ostream& out, const customer& obj) {
		//out << obj.fname << " " << obj.lname << endl;
		out << "customer id = " << obj.cid << endl;
		cout << "customer information = " << obj.a1;


		return out;

	}

	void setcid(int id) {
		cid = id;

	}
	int getcid() {
		return cid;
	}

	void setbookinghistory(service** a) {
		bookinghistory = new service * [1];
		for (int i = 0; i < 1; i++)
		{
			bookinghistory[i] = new service[100];
		}

		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				bookinghistory[i][j] = a[i][j];
			}
		}
	}

	service** getbookinghistory() { return bookinghistory; }

	void setperson(person& b) {

		a1.setage(b.getage());
		a1.setpid(b.getpid());
		a1.setpDate(b.getpDate());
		a1.setpName(b.getpName());
		//person(int ag, int id, name pn, date da)
	}
	person getperson() {
		return a1;
	}
	//destructor
	void print() {
		person::print();
		cout << "customer ID = " << cid;

	}
	~customer() {
		/*for (int i = 0; i < 100; i++)
		{
			delete[]bookinghistory[i];

		}
		delete[] bookinghistory;
		bookinghistory = NULL;*/
	}
};

class driver :public person {
	int did;
	char** licencesList;
	int nooflicences;
	float overallranking;
	float salary;
	int experience;
	int status;
	service** servicehistory;
	person a2;

public:
	driver() {
		did = 0;
		licencesList = nullptr;

		nooflicences = 0;
		overallranking = 0;
		salary = 0;
		experience = 0;
		status = 1;
		servicehistory = new service * [100];
		for (int i = 0; i < 100; i++)
		{
			servicehistory[i] = new service[100];

		}

	}
	driver(int id, char** li, int noli, float ora, float sal, int ex, int st, service** a, person b) {

		did = id;
		licencesList = new char* [10];
		for (int i = 0; i < 10; i++)
		{
			licencesList[i] = new char[10];
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				licencesList[i][j] = li[i][j];

			}

		}
		nooflicences = noli;
		overallranking = ora;
		salary = sal;
		experience = ex;
		status = st;
		servicehistory = new service * [100];
		for (int i = 0; i < 100; i++)
		{
			servicehistory[i] = new service[100];

		}
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				servicehistory[i][j] = a[i][j];

			}

		}

		a2 = b;
	}

	void setdid(int id) {
		did = id;
	}
	void setll3(char** li, int a, string b) {
		licencesList = new char* [a + 1];

		vector<string> result;
		stringstream s_stream(b);
		while (s_stream.good()) {
			string substr;
			getline(s_stream, substr, ',');
			result.push_back(substr);
		}
		int g = 0;

		for (int i = 1; i < a + 1; i++)
		{

			char* temp = new char[12 + (i)];
			for (int j = 0; j < result.at(12 + (i)).length(); j++)
			{

				g = result.at(12 + (i)).length();
				temp[j] = result.at(12 + (i))[j];

			}
			licencesList[i] = temp;
			licencesList[i][g] = '\0';
			//cout << licencesList[i] << endl;

		}

		//cout << licencesList[0];
	}

	void setll1(int g, char** c)
	{
		licencesList = new char* [g];
		int g1 = 0;
		int* d = new int[g];

		for (int i = 0; i < g; i++) {
			int k = strlen(c[i]);
			char* temp = new char[k + 1];
			for (int j = 0; j < k; j++) {
				temp[j] = c[i][j];
			}
			temp[k] = '\0';

			licencesList[i] = temp;

		}


		/*for (int i = 0; i < g; i++)
		{
			cout<<" &&&&& " << this->licencesList[i];

		}*/
	}
	void setnooflicences(int noli) {
		nooflicences = noli;
	}
	void setoverallranking(float ora) {
		overallranking = ora;
	}
	void setsalary(float sal) {
		salary = sal;
	}
	void setexperiance(int ex) {
		experience = ex;
	}
	void setstatus(int st) {
		status = st;
	}
	void setservicehistory(service** a) {
		servicehistory = new service * [100];
		for (int i = 0; i < 100; i++)
		{
			servicehistory[i] = new service[100];

		}
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				servicehistory[i][j] = a[i][j];

			}

		}

	}

	int getdid() {
		return did;

	}

	/*char** getll() {
		return licencesList;
	}*/
	int getnooflicence() {
		return nooflicences;

	}
	float getoverallranking() {
		return overallranking;
	}
	float getsalary() {
		return salary;
	}
	int getexperiance() {
		return experience;
	}
	int getstatus() {
		return status;

	}
	service** getservicehistory() {
		return servicehistory;
	}

	char** getsll() {
		//cout << licencesList[0] << "####";
		/*for (int i = 0; i < nooflicences; i++)
		{
			cout << licencesList[i]<<"####";
		}*/
		return licencesList;
	}
	friend ostream& operator<<(ostream& out, const driver& obj) {
		//out << obj.did << " " << obj.experience << " " << obj.nooflicences << " " << obj.salary << " " << obj.overallranking;
		out << "driver ID= " << obj.did << endl;
		out << "drivers " << obj.a2;
		out << "driver experience = " << obj.experience << endl;
		out << "number of licences = " << obj.nooflicences << endl;
		out << "salary= " << obj.salary << endl;
		out << "ranking = " << obj.overallranking << endl;
		cout << endl;
		return out;

	}

	void setperson(person& b) {

		a2.setage(b.getage());
		a2.setpid(b.getpid());
		a2.setpDate(b.getpDate());
		a2.setpName(b.getpName());
		//person(int ag, int id, name pn, date da)
	}
	person getperson() {
		return a2;
	}

	~driver()
	{/*
		for (int i = 0; i < 100; i++)
		{
			delete[]servicehistory[i];

		}
		delete[] servicehistory;
		servicehistory = NULL;

		for (int i = 0; i < nooflicences; i++)
		{
			delete[]licencesList[i];

		}
		delete[] licencesList;
		licencesList = NULL;*/

	}
};

class feature {
	int fid;
	char* description;
	float cost;

public:
	feature() {
		fid = 0;
		description = new char[100];
		description = nullptr;
		cost = 0;
	}
	/// maybe error below

	feature(int a, char* b, float c) {
		fid = a;
		int len = strlen(b);
		description = new char[len];
		for (int i = 0; i < len; i++)
		{
			description[i] = b[i];
		}
		cost = c;
	}

	void setfif(int a) {
		fid = a;
	}
	void setdespriction(char* b) {
		int len = strlen(b);
		description = new char[len + 1];
		for (int i = 0; i < len + 1; i++)
		{
			description[i] = b[i];
		}
		//description(len+1) = '\0';
	}
	void setcost(float c) {
		cost = c;
	}
	int getfid() {
		return fid;
	}
	char* getdescription() {
		return description;
	}
	float getcost()
	{
		return cost;
	}
	friend ostream& operator<<(ostream& out, const feature& obj) {
		//out << obj.did << " " << obj.experience << " " << obj.nooflicences << " " << obj.salary << " " << obj.overallranking;
		out << "cost= " << obj.cost << endl;
		out << "description " << obj.description;
		out << "feature id = " << obj.fid << endl;

		cout << endl;
		return out;

	}
	~feature() {
		//delete[]description;
	}
};

class vehicle {
	int vid;
	int regnum;
	float avgmileage;
	char* licencetype;
	bool status;
	char* fueltype;
	float overallranking;
	date manufacturingdate;
	feature* list;
	service** servicehistory;
public:
	vehicle() {


		vid = 0;
		regnum = 0;
		avgmileage = 0;
		licencetype = new char[10];
		licencetype = nullptr;
		status = true;
		fueltype = new char[10];
		fueltype = nullptr;
		overallranking = 0;


		list = new feature[10];
		list = nullptr;
		servicehistory = new service * [100];
		for (int i = 0; i < 100; i++)
		{
			servicehistory[i] = new service[100];

		}
		servicehistory = nullptr;


	}
	vehicle(int id, int renum, float avm, char* lt, bool st, char* fl, float ov, date a, feature* b, service** c) {


		vid = id;
		regnum = renum;
		avgmileage = avm;

		//licencetype = nullptr;
		int len = strlen(lt);
		licencetype = new char[len + 1];
		for (int i = 0; i < len + 1; i++)
		{
			licencetype[i] = lt[i];
		}
		status = st;

		//fueltype = nullptr;
		int len1 = strlen(fl);
		fueltype = new char[len1 + 1];
		for (int i = 0; i < len1 + 1; i++)
		{
			fueltype[i] = fl[i];
		}
		overallranking = ov;
		manufacturingdate = a;
		list = new feature[10];
		for (int i = 0; i < 10; i++)
		{
			list[i] = b[i];
		}

		servicehistory = new service * [100];
		for (int i = 0; i < 100; i++)
		{
			servicehistory[i] = new service[100];

		}
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				servicehistory[i][j] = c[i][j];

			}

		}
	}

	void setvehicleservicehistory(service** a) {
		servicehistory = new service * [100];
		for (int i = 0; i < 100; i++)
		{
			servicehistory[i] = new service[100];

		}
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				servicehistory[i][j] = a[i][j];

			}

		}

	}

	void setvid(int id) {
		vid = id;
	}
	void setregnum(int renum) {
		regnum = renum;
	}
	void setavgmileage(float avm) {
		avgmileage = avm;
	}
	void setlt(char* lt) {
		int len = strlen(lt);
		licencetype = new char[len];
		for (int i = 0; i < len; i++)
		{
			licencetype[i] = lt[i];
		}
		licencetype[len] = '\0';

		/*int len1 = strlen(lt);
		licencetype = new char[len1 + 1];
		for (int i = 0; i < len1 + 1; i++)
		{
			licencetype[i] = lt[i];
		}
		licencetype[len1] = '\0';*/
	}
	void setstatus(bool st) {
		status = st;
	}
	void setft(char* ft) {
		int len = strlen(ft);
		fueltype = new char[len];
		for (int i = 0; i < len; i++)
		{
			fueltype[i] = ft[i];
		}
		fueltype[len] = '\0';
	}
	void setoverallranking(float ovr) {
		overallranking = ovr;

	}
	void setvehdate(date a) {
		manufacturingdate = a;

	}
	void setvehfeature(feature* b) {
		list = new feature[10];
		for (int i = 0; i < 10; i++)
		{
			list[i] = b[i];
		}
	}

	int getvid() {
		return vid;
	}
	int getregnum() {
		return regnum;
	}
	float getavgmileage() { return avgmileage; }
	char* getlicencetype() { return licencetype; }
	bool getstatus() {
		return status;
	}
	char* getfueltype() {
		return fueltype;
	}

	float getoverallranking() { return overallranking; }
	date getvehdate() { return manufacturingdate; }
	service** getvehservicehistory() { return servicehistory; }
	feature* getlist() { return list; }



	friend ostream& operator<<(ostream& out, const vehicle& obj) {
		//out << obj.did << " " << obj.experience << " " << obj.nooflicences << " " << obj.salary << " " << obj.overallranking;
		out << "vehicle ID= " << obj.vid;
		out << "manufacturing " << obj.manufacturingdate;
		out << "average mileage = " << obj.avgmileage << endl;
		out << "registration number= " << obj.regnum << endl;
		out << "status = " << obj.status << endl;
		out << "ranking = " << obj.overallranking << endl;
		out << "features = " << endl;
		out << "cost =" << obj.list->getcost() << endl;
		out << "description =" << obj.list->getdescription() << endl;
		out << "fuel type = " << obj.fueltype;

		cout << endl;
		return out;

	}
	~vehicle()
	{
		//delete[] fueltype;
	}
};


class TMS {

	driver* d;
	customer* c;
	ride* rrr;
	vehicle* v;
	delivery* dd;
	int customerCounter;


public:


	TMS() {
		//d=new driver[]
		d = new driver[10];
		//int driverCount = 0;
		v = new vehicle[15];
		c = new customer[20];
		rrr = new ride[100];
		dd = new delivery[100];
		customerCounter = 0;
	}

	void setdriver(driver* d1) {
		d = new driver[10];
		int driverCount = 0;

		d = d1;


	}

	void setcustomer(customer* c1) {

		c = new customer[20];
		int customerCount = 0;

	}
	void setvehicle(vehicle* c1) {


		v = new vehicle[15];
		//int vehicleCount = 0;
		v = c1;
	}
	void setrideservice(ride* c1) {

		rrr = new ride[100];
		//int rideCount1 = 0;
		rrr = c1;

	}
	void setdeliveryservice(delivery* c1) {

		dd = new delivery[100];
		//int deliveryCount = 0;
		dd = c1;
		//cout << dd[0];
	}
	void task1(int customerCount) {

		if (customerCount < 20) {
			int cid, m, y, da;
			cout << "enter id=";
			cin >> cid;
			char* fname1;
			fname1 = new char[50];
			char* lname1;
			lname1 = new char[50];
			cout << "enter firstname = ";
			cin >> fname1;
			cout << "enter lastname = ";
			cin >> lname1;
			int ag;
			cout << "enter age = ";
			cin >> ag;
			cout << "enter date of birth= ";
			cin >> da;
			cout << "enter year of birth= ";
			cin >> y;
			cout << "enter month of birth= ";
			cin >> m;

			//c1.setage(ag);
			name  a(fname1, lname1);
			date dat(da, m, y);
			person a2(ag, cid, a, dat);
			service** se = nullptr;

			customer c1;

			//cout << a1;
			c1.setcid(cid);
			c1.setperson(a2);
			c1.setage(ag);
			c1.setpid(001);
			//	c1.setbookinghistory(se);


			//adding in customer array

			c[customerCount] = c1;
			customerCount++;
			delete []fname1;
			delete [] lname1;
		}
		else {
			cout << "CUSTOMER CAPACITY IS FULL" << endl;
		}


		fstream myfile2;
		myfile2.open("customer.txt", ios::out);
		if (!myfile2) {
			cout << "File not created!";
		}
		else {
			//cout << "File created successfully!";
			for (int i = 0; i < customerCount; i++) {
				myfile2 << c[i].getcid() << ",";
				person ptemp = c[i].getperson();
				//cout << ptemp.getpName().getf();
				myfile2 << ptemp.getpName().getf() << "," << ptemp.getpName().getl() << ",";
				myfile2 << c[i].getage() << ",";
				//date pdate = c[i].getpDate();
				myfile2 << ptemp.getpDate().getdate() << "," << ptemp.getpDate().getmonth() << "," << ptemp.getpDate().getyear() << endl;
			}
			myfile2.close();
		}


	}


};

//customer not complete

int main() {

	driver* d;
	d = new driver[10];
	int driverCount = 0;


	vehicle* v;
	v = new vehicle[15];
	int vehicleCount = 0;


	customer* c;
	c = new customer[20];
	int customerCount = 0;


	ride* rrr;
	rrr = new ride[100];
	int rideCount1 = 0;


	delivery* dd;
	dd = new delivery[100];
	int deliveryCount = 0;

	
	///load customers
	string line;
	ifstream myfile("customer.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line) && customerCount < 20)
		{
			vector<string> result;
			stringstream s_stream(line);
			while (s_stream.good()) {
				string substr;
				getline(s_stream, substr, ',');
				result.push_back(substr);
			}

			int cid = stoi(result.at(0));
			char* fname = new char[result.at(1).length() + 1];
			int ss = result.at(1).length();
			for (int i = 0; i < ss; i++) {
				string s = result.at(1);
				fname[i] = s[i];
			}
			fname[ss] = '\0';
			char* lname = new char[result.at(2).length() + 1];
			ss = result.at(2).length();
			for (int i = 0; i < ss; i++) {
				string s = result.at(2);
				lname[i] = s[i];
			}
			lname[ss] = '\0';
			name  a(fname, lname);
			int ag = stoi(result.at(3));
			int da = stoi(result.at(4));
			int m = stoi(result.at(5));
			int y = stoi(result.at(6));

			date dat(da, m, y);
			person a1(ag, cid, a, dat);
			service** se = nullptr;

			customer c1;

			//cout << a1;
			c1.setcid(cid);
			c1.setperson(a1);
			c1.setage(ag);
			c1.setpid(001);

			// add in customer array
			c[customerCount] = c1;
			customerCount++;
		}
		myfile.close();
	}

	else cout << "Unable to open file";




	//load drivers


	string line1;
	ifstream myfile1("drivers.txt");
	if (myfile1.is_open())
	{
		while (getline(myfile1, line1) && driverCount < 10)
		{
			vector<string> result;
			stringstream s_stream(line1);
			while (s_stream.good()) {
				string substr;
				getline(s_stream, substr, ',');
				result.push_back(substr);
			}

			int did = stoi(result.at(0));
			int ppid = stoi(result.at(1));
			char* fname = new char[result.at(2).length() + 1];
			int ss1 = result.at(2).length();
			for (int i = 0; i < ss1; i++) {
				string s = result.at(2);
				fname[i] = s[i];
			}
			fname[ss1] = '\0';
			char* lname = new char[result.at(3).length() + 1];
			int ss2 = result.at(3).length();
			for (int i = 0; i < ss2; i++) {
				string s = result.at(3);
				lname[i] = s[i];
			}
			lname[ss2] = '\0';
			name  a(fname, lname);
			int ag = stoi(result.at(4));
			int da = stoi(result.at(5));
			int m = stoi(result.at(6));
			int y = stoi(result.at(7));
			int noofli = stoi(result.at(8));
			float rank = stof(result.at(9));
			float salary = stof(result.at(10));
			int exp = stoi(result.at(11));
			int status = stoi(result.at(12));

			char** typeofli = new char* [noofli + 1];
			int g = 0;
			string h = result.at(12 + (1));

			for (int i = 0; i < noofli; i++)
			{

				int size1 = result.at(12 + (i + 1)).length();
				char* temp = new char[result.at(12 + (i + 1)).length()];

				for (int j = 0; j < size1; j++)
				{

					g = result.at(12 + (i + 1)).length();
					string h = result.at(12 + (i + 1));
					temp[j] = h[j];


				}
				typeofli[i] = temp;
				typeofli[i][g + 1] = '\0';

			}

			date datt(da, m, y);
			person a11(ag, did, a, datt);
			service** se = nullptr;


			driver c1;

			//cout << a1;
			c1.setdid(did);
			c1.setperson(a11);
			c1.setage(ag);
			c1.setpid(001);

			c1.setexperiance(exp);
			c1.setstatus(status);
			c1.setpid(ppid);
			c1.setnooflicences(noofli);
			c1.setoverallranking(rank);
			c1.setsalary(salary);
			c1.setll3(typeofli, noofli, line1);
			//cout << c1;
			// add in customer array;
			d[driverCount] = c1;
			driverCount++;
		}
		myfile1.close();
	}

	else cout << "Unable to open file";

	

	//load vehicles




	string line2;
	ifstream myfile2("vehicle.txt");
	if (myfile2.is_open())
	{
		while (getline(myfile2, line2) && vehicleCount < 15)
		{
			vector<string> result;
			stringstream s_stream(line2);
			while (s_stream.good())
			{
				string substr;
				getline(s_stream, substr, ',');
				result.push_back(substr);
			}

			int fid = stoi(result.at(0));
			int vid = stoi(result.at(1));
			int regnum = stoi(result.at(2));
			float cost = stof(result.at(3));
			int daa = stoi(result.at(4));
			int moo = stoi(result.at(5));
			int yee = stoi(result.at(6));
			float ra = stof(result.at(7));
			string stat = (result.at(8));
			bool statu;
			if (stat == "true")
			{
				statu = true;
			}
			else { statu = false; }


			float milage = stof(result.at(9));


			char* fueltype = new char[result.at(10).length() + 1];
			int si = result.at(10).length();

			for (int i = 0; i < si; i++)
			{
				string fy = result.at(10);
				fueltype[i] = fy[i];

			}
			fueltype[si] = '\0';




			char* description = new char[result.at(11).length() + 1];
			int sii = result.at(11).length();

			for (int i = 0; i < result.at(11).length(); i++)
			{
				string ffy = result.at(11);
				description[i] = ffy[i];

			}
			description[sii] = '\0';



			char* llll = new char[result.at(12).length() + 1];
			int siii = result.at(12).length();

			for (int i = 0; i < siii; i++)
			{
				string fffy = result.at(12);
				llll[i] = fffy[i];

			}
			llll[siii] = '\0';

			vehicle v1;


			date w(daa, moo, yee);
			feature* r = new feature;
			r->setcost(cost);
			r->setdespriction(description);
			r->setfif(fid);

			v1.setavgmileage(milage);
			v1.setft(fueltype);
			v1.setlt(llll);
			v1.setoverallranking(ra);
			v1.setregnum(regnum);
			v1.setstatus(statu);
			v1.setvehdate(w);
			v1.setvehfeature(r);
			v1.setvid(vid);

			// cout << v1;


			v[vehicleCount] = v1;
			vehicleCount++;
		}

		myfile2.close();
	}

	else cout << "Unable to open file";







	//load ride services
	string line3;
	ifstream myfile3("rideservice.txt");
	if (myfile3.is_open())
	{
		while (getline(myfile3, line3) && rideCount1 < 100)
		{
			vector<string> result;
			stringstream s_stream(line3);
			while (s_stream.good()) {
				string substr;
				getline(s_stream, substr, ',');
				result.push_back(substr);
			}

			char* source = new char[result.at(0).length() + 1];
			int si1 = result.at(0).length();

			for (int i = 0; i < si1; i++)
			{
				string fy = result.at(0);
				source[i] = fy[i];

			}
			source[si1] = '\0';

			char* destination = new char[result.at(1).length() + 1];
			int si2 = result.at(1).length();

			for (int i = 0; i < si2; i++)
			{
				string fy = result.at(1);
				destination[i] = fy[i];

			}
			destination[si2] = '\0';

			float distance = stof(result.at(2));
			int datee = stoi(result.at(3));
			int montth = stoi(result.at(4));
			int yeear = stoi(result.at(5));
			int hhr = stoi(result.at(6));
			int mmin = stoi(result.at(7));
			int ssec = stoi(result.at(8));
			string l = result.at(9);
			bool sta;
			if (l == "true")
			{
				sta = true;
			}
			else
			{
				sta = false;
			}
			float fuelrate = stof(result.at(10));
			int CID = stoi(result.at(11));

			int DID = stoi(result.at(12));

			int VID = stoi(result.at(13));
			int noofpas = stoi(result.at(14));
			char* type = new char[result.at(15).length() + 1];
			int si22 = result.at(15).length();

			for (int i = 0; i < si22; i++)
			{
				string fy = result.at(15);
				type[i] = fy[i];

			}
			type[si22] = '\0';

			float drank = stof(result.at(16));
			float vrank = stof(result.at(17));
			//cout << "hi";
			//cout << vrank;
			int ff = stoi(result.at(18));
			//cout << ff;
			date r(datee, montth, yeear);
			mtime y(hhr, mmin, ssec);
			service s1;

			s1.setci(CID);
			//cout << r;
			s1.setdi(DID);
			s1.setvi(VID);
			s1.setdistance(distance);
			s1.setdestination(destination);
			s1.setsource(source);
			s1.setstatus(sta);
			s1.setfulerate(fuelrate);
			s1.setserdate(r);
			s1.setsertime(y);
			ride r1;
			//cout << ff;
			r1.setservice(s1);
			r1.setdriverrank(drank);
			r1.setvehiclerank(vrank);
			r1.setridetype(type);
			r1.setpassengers(noofpas);
			r1.setff(ff);
			//cout << r1;;
			//cout << r1.getvehicleank();
			rrr[rideCount1] = r1;
			rideCount1++;
		}
		myfile3.close();
	}

	else cout << "Unable to open file";


	//load delivery service

	string line5;
	ifstream myfile4("deliveryservice.txt");
	if (myfile4.is_open())
	{
		while (getline(myfile4, line5) && deliveryCount < 100)
		{
			vector<string> result;
			stringstream s_stream(line5);
			while (s_stream.good()) {
				string substr;
				getline(s_stream, substr, ',');
				result.push_back(substr);
			}

			char* source = new char[result.at(0).length() + 1];
			int si1 = result.at(0).length();

			for (int i = 0; i < si1; i++)
			{
				string fy = result.at(0);
				source[i] = fy[i];

			}
			source[si1] = '\0';

			char* destination = new char[result.at(1).length() + 1];
			int si2 = result.at(1).length();

			for (int i = 0; i < si2; i++)
			{
				string fy = result.at(1);
				destination[i] = fy[i];

			}
			destination[si2] = '\0';

			float distance = stof(result.at(2));
			int datee = stoi(result.at(3));
			int montth = stoi(result.at(4));
			int yeear = stoi(result.at(5));
			int hhr = stoi(result.at(6));
			int mmin = stoi(result.at(7));
			int ssec = stoi(result.at(8));
			string l = result.at(9);
			bool sta;
			if (l == "true")
			{
				sta = true;
			}
			else
			{
				sta = false;
			}
			float fuelrate = stof(result.at(10));
			int CID = stoi(result.at(11));

			int DID = stoi(result.at(12));

			int VID = stoi(result.at(13));
			float weight = stof(result.at(14));
			char* gtype = new char[result.at(15).length() + 1];
			int si22 = result.at(15).length();

			for (int i = 0; i < si22; i++)
			{
				string fy = result.at(15);
				gtype[i] = fy[i];

			}
			gtype[si22] = '\0';
			float drank = stof(result.at(16));
			float vrank = stof(result.at(17));
			int ff = stoi(result.at(18));
			date r(datee, montth, yeear);
			mtime y(hhr, mmin, ssec);
			service s11;

			s11.setci(CID);
			//cout << r;
			s11.setdi(DID);
			s11.setvi(VID);
			s11.setdistance(distance);
			s11.setdestination(destination);
			s11.setsource(source);
			s11.setstatus(sta);
			s11.setfulerate(fuelrate);
			s11.setserdate(r);
			s11.setsertime(y);
			delivery r12;
			r12.setff(ff);
			r12.setservice(s11);
			r12.setdriverrank(drank);
			r12.setvehiclerank(vrank);
			r12.setgoodstype(gtype);
			r12.setgoodweight(weight);

			//cout << r12;;
			//cout << r1.getvehicleank();
			dd[deliveryCount] = r12;
			deliveryCount++;
		}
		myfile3.close();
	}


	else cout << "Unable to open file";
	//cout << deliveryCount;

	TMS classmangement;
	classmangement.setdeliveryservice(dd);
	classmangement.setdriver(d);
	classmangement.setcustomer(c);
	classmangement.setvehicle(v);
	classmangement.setrideservice(rrr);




	//multan,lahore,12.7,1,5,2002,1,6,8,true,145.7,12,13,24

   //menu
	int op = 0;
	

	while (op != -1)
	{
		cout << "1.add customer" << endl;
		cout << "2.Add or remove a Driver" << endl;
		cout << "3. Add or remove a Vehicle" << endl;
		cout << "4. Print List of All Customers" << endl;
		cout << "5. Print List of All drivers" << endl;
		cout << "6. Print complete list of vehicles with details by their category." << endl;

		cout << "7.Print complete details and service history of a particular vehicle." << endl;
		cout << "8.Print complete history of a particular customer." << endl;
		cout << "9.Print complete history of a driver including services." << endl;
		cout << "10. Print list of all drivers who have ranking above 4.5." << endl;
		cout << "11. Print list of all drivers who have multiple licenses and their license information too." << endl;
		cout << "12. Print updated salary of all drivers based on their updated ranking." << endl;

		cout << "13.Add a Service request." << endl;
		cout << "14.Cancel a booking." << endl;
		cout << "15.Complete a service" << endl;
		cout << "16.Print details of all Customers, who used the same vehicle in a ride service on a different date." << endl;
		cout << "17. Print the List of all Drivers who completed delivery services on same days." << endl;
		cout << "18.Print details of all pending services on a particular date." << endl;


		cout << "19.Print details of all pending services of a particular driver." << endl;
		cout << "20.Print details of all canceled services by a customer." << endl;
		cout << "21.EXIT " << endl;
		cout << "enter option = ";
		cin >> op;


		system("cls");
		if (op == 1)//complete
		{
			//classmangement.task1(customerCount);
			if (customerCount < 20) {
				int cid, m, y, da;
				cout << "enter id=";
				cin >> cid;
				char* fname1;
				fname1 = new char[50];
				char* lname1;
				lname1 = new char[50];
				cout << "enter firstname = ";
				cin >> fname1;
				cout << "enter lastname = ";
				cin >> lname1;
				int ag;
				cout << "enter age = ";
				cin >> ag;
				cout << "enter date of birth= ";
				cin >> da;
				cout << "enter year of birth= ";
				cin >> y;
				cout << "enter month of birth= ";
				cin >> m;

				//c1.setage(ag);
				name  a(fname1, lname1);
				date dat(da, m, y);
				person a2(ag, cid, a, dat);
				service** se = nullptr;

				customer c1;

				//cout << a1;
				c1.setcid(cid);
				c1.setperson(a2);
				c1.setage(ag);
				c1.setpid(001);
				//	c1.setbookinghistory(se);


				//adding in customer array

				c[customerCount] = c1;
				customerCount++;
				delete[]fname1;
				delete[] lname1;
			}
			else {
				cout << "CUSTOMER CAPACITY IS FULL" << endl;
			}


			fstream myfile2;
			myfile2.open("customer.txt", ios::out);
			if (!myfile2) {
				cout << "File not created!";
			}
			else {
			//	cout << "File created successfully!";
				for (int i = 0; i < customerCount; i++) {
					myfile2 << c[i].getcid() << ",";
					person ptemp = c[i].getperson();
					//cout << ptemp.getpName().getf();
					myfile2 << ptemp.getpName().getf() << "," << ptemp.getpName().getl() << ",";
					myfile2 << c[i].getage() << ",";
					//date pdate = c[i].getpDate();
					myfile2 << ptemp.getpDate().getdate() << "," << ptemp.getpDate().getmonth() << "," << ptemp.getpDate().getyear() << endl;
				}
				myfile2.close();
			}


		}
		
		if (op == 2)//"2.Add or remove a Driver"
		{//10 drivers
			int op2 = 0;
			cout << "1.add driver." << endl;
			cout << "2.remove driver." << endl;

			cin >> op2;
			if (op2 == 1)
			{
				if (driverCount < 10) {
					int did, mmm, yyy, daaa;
					cout << "enter id=";
					cin >> did;
					char* fname11;
					fname11 = new char[50];
					char* lname11;
					lname11 = new char[50];
					cout << "enter firstname = ";
					cin >> fname11;
					cout << "enter lastname = ";
					cin >> lname11;
					int agg;
					cout << "enter age = ";
					cin >> agg;
					cout << "enter date of birth= ";
					cin >> daaa;
					cout << "enter year of birth= ";
					cin >> yyy;
					cout << "enter month of birth= ";
					cin >> mmm;
					int exp;
					cout << "experience= ";
					cin >> exp;
					int noofli = 0;
					cout << "no of license = ";
					cin >> noofli;
					int x = noofli;
					cout << "enter type of licence= ";
					char** a;
					a = new char* [noofli];
					int* mm = new int[x];


					cout << "1.motorcar /jeep licence." << endl;
					cout << "2.motorbike/rickshaw." << endl;
					cout << "3.LTV." << endl;
					cout << "4.HTV." << endl;
					cout << "5.tractor." << endl;
					cout << "6.PSV." << endl;
					cout << "7.international driver permit.";
					for (int i = 0; i < noofli; i++)
					{
						cout << "enter option = ";
						cin >> mm[i];
						cout << endl;
					}



					int g = 0;
					for (int i = 0; i < noofli; i++)
					{
						//cout << g;
						if (mm[g] == 1)
						{
							char* temp = new char[13];
							string j1 = "motorcar/jeep";
							for (int k = 0; k < 13; k++)
							{
								temp[k] = j1[k];
							}

							a[i] = temp;
							//cout << a[i];
							a[i][13] = '\0';
						}
						if (mm[g] == 2)
						{
							char* temp = new char[18];

							string j2 = "motorbike/rickshaw";
							for (int k = 0; k < 18; k++)
							{
								temp[k] = j2[k];
							}

							a[i] = temp;
							///cout << a[i];
							a[i][18] = '\0';
						}
						if (mm[g] == 3)
						{

							char* temp = new char[4];
							string j3 = "LTV";

							for (int k = 0; k < 4; k++)
							{
								//cout << "hi";
								temp[k] = j3[k];
							}

							a[i] = temp;
							//cout << a[i];
							a[i][4] = '\0';

						}
						if (mm[g] == 4)
						{
							char* temp = new char[4];
							string j4 = "HTV";
							for (int k = 0; k < 4; k++)
							{
								temp[k] = j4[k];
							}

							//cout << temp;
							a[i] = temp;
							//cout << a[i];
							a[i][4] = '\0';

						}

						if (mm[g] == 5)
						{
							char* temp = new char[7];
							string j5 = "tractor";
							for (int k = 0; k < 7; k++)
							{
								temp[k] = j5[k];
							}

							a[i] = temp;
							//cout << a[i];
							a[i][7] = '\0';

						}
						if (mm[g] == 6)
						{

							char* temp = new char[4];
							string j6 = "PSV";
							for (int k = 0; k < 4; k++)
							{
								temp[k] = j6[k];
							}

							a[i] = temp;
							//	cout << a[i];
							a[i][4] = '\0';

						}
						if (mm[g] == 7)
						{
							char* temp = new char[27];
							string j7 = "international driver permit";
							for (int k = 0; k < 27; k++)
							{
								temp[k] = j7[k];
							}

							a[i] = temp;

							a[i][27] = '\0';
							//cout << a[i];
							//cout << a[i];
						}

						++g;
						//cout << i;
						cout << endl;
						//cout << a[i];
					}



					//c1.setage(ag);
					name  a1(fname11, lname11);
					date dat(daaa, mmm, yyy);
					person a2(agg, did, a1, dat);
					service** se = nullptr;
					float x11 = 1000;
					driver c1;

					//cout << a1;
					//c1.setpid(9);
					c1.setdid(did);
					c1.setperson(a2);
					c1.setage(agg);
					c1.setpid(001);
					//	c1.setbookinghistory(se);
					c1.setexperiance(exp);
					c1.setstatus(1);
					c1.setnooflicences(noofli);
					c1.setll1(noofli, a);
					c1.setsalary(x11);
					c1.setpDate(dat);
					c1.setoverallranking(0);
					//c1.setservicehistory(se);
					//cout << c1.getsll();
					/*char **dsu = c1.getsll();
					cout << dsu[0]<<"fgfd";*/

					d[driverCount] = c1;
					driverCount++;
					delete []fname11;
					delete []lname11;
					delete []mm;
					/*for (int i = 0; i < noofli; i++)
					{
						delete[] a[i];

					}
					delete[] a;*/
				}
				else {
					cout << "driver CAPACITY IS FULL" << endl;
				}

				/*char ** a = d[0].getsll();
				cout << a[0];*/


			}


			else if (op == 2) {
				cout << "Enter ID of driver to delete: ";
				int idd;
				cin >> idd;
				bool found = false;
				int index = 0;
				for (int i = 0; i < driverCount && found == false; i++) {
					driver temp = d[i];
					if (temp.getdid() == idd) {
						index = i;
						found = true;
					}

				}

				for (int i = index; i < driverCount - 1; i++) {
					d[i] = d[i + 1];
				}

				driverCount--;


			}



			fstream myfile3;
			myfile3.open("drivers.txt", ios::out);
			if (!myfile3) {
				cout << "File not created!";
			}
			else {
				//cout << "File created successfully!";

				for (int i = 0; i < driverCount; i++) {
					//char **a = d[i].getsll();
					myfile3 << d[i].getdid() << ",";
					myfile3 << d[i].getpid() << ",";
					person ptemp = d[i].getperson();
					//cout << ptemp.getpName().getf();
					myfile3 << ptemp.getpName().getf() << "," << ptemp.getpName().getl() << ",";
					myfile3 << d[i].getage() << ",";
					//date pdate = c[i].getpDate();
					myfile3 << ptemp.getpDate().getdate() << "," << ptemp.getpDate().getmonth() << "," << ptemp.getpDate().getyear() << ",";
					myfile3 << d[i].getnooflicence() << ",";
					myfile3 << d[i].getoverallranking();
					myfile3 << "," << d[i].getsalary() << ",";
					myfile3 << d[i].getexperiance() << ",";
					myfile3 << d[i].getstatus() << ",";
					//myfile3 << d[i].getnooflicence() << "," << d[i].getoverallranking() << "," << d[i].getsalary() << "," << d[i].getexperiance() << "," << d[i].getstatus();
					//cout << d[i].getstatus();
					//char **a = d[i].getsll();
					/////
					/*for (int i = 0; i < d[i].getnooflicence(); i++) {
						cout<<"*****" << a[i];
					}
*/
/////


					for (int j = 0; j < d[i].getnooflicence(); j++)
					{
						if (j != d[i].getnooflicence())
						{
							myfile3 << d[j].getsll() << ",";
						}
						else {
							myfile3 << d[j].getsll();
						}

					}

					myfile3 << endl;
				}
				myfile3.close();
			}









		}
		if (op == 3)//add remove vehicle
		{

			int op2 = 0;
			cout << "1.add vehicle." << endl;
			cout << "2.remove vehicle." << endl;

			cin >> op2;
			if (op2 == 1)
			{


				if (vehicleCount < 15) {
					int vid, fid, m, y, da;
					cout << "enter id=";
					cin >> vid;
					cout << "enter feature id= ";
					cin >> fid;
					int cost;
					cout << "enter cost = ";
					cin >> cost;
					int regum;
					cout << "enter registration number= ";
					cin >> regum;
					cout << "enter date of manufacturing= ";
					cin >> da;
					cout << "enter year of manufacturing= ";
					cin >> y;
					cout << "enter month of manufacturing= ";
					cin >> m;
					float avg;
					cout << "average mileage = ";
					cin >> avg;
					char* fuel;
					fuel = new char[50];
					cout << "enter fueltype(petrol/disel) = ";
					cin >> fuel;
					char* des;
					des = new char[100];
					cout << "enter description = ";
					cin >> des;
					char* licencetype;
					licencetype = new char[100];
					cout << "enter licencetype = ";
					cin >> licencetype;

					date dat(da, m, y);
					feature* list = new feature;
					list->setfif(fid);
					list->setdespriction(des);
					list->setcost(cost);
					service** se = nullptr;

					vehicle c1;

					c1.setvehfeature(list);
					c1.setvid(fid);
					c1.setvehdate(dat);
					c1.setregnum(regum);
					c1.setoverallranking(0);
					c1.setft(fuel);

					c1.setavgmileage(avg);
					c1.setstatus(true);
					c1.setlt(licencetype);

					v[vehicleCount] = c1;
					vehicleCount++;
					delete[]licencetype;
					delete[] des;
				}
				else {
					cout << "CUSTOMER CAPACITY IS FULL" << endl;
				}

			}
			else if (op2 == 2) {
				cout << "Enter ID of vehicle to delete: ";
				int idd;
				cin >> idd;
				bool found = false;
				int index = 0;
				for (int i = 0; i < vehicleCount && found == false; i++) {
					vehicle temp = v[i];
					if (temp.getvid() == idd) {
						index = i;
						found = true;
					}

				}

				for (int i = index; i < vehicleCount - 1; i++) {
					v[i] = v[i + 1];
				}

				vehicleCount--;
			}

			////////////////////////////////


			fstream myfile7;
			myfile7.open("vehicle.txt", ios::out);
			if (!myfile7) {
				cout << "File not created!";
			}
			else {
				//cout << "File created successfully!";

				for (int i = 0; i < vehicleCount; i++) {
					//char **a = d[i].getsll();
					myfile7 << v[i].getlist()->getfid() << ",";
					myfile7 << v[i].getvid() << ",";
					date ptemp = v[i].getvehdate();
					//cout << ptemp.getpName().getf();
					myfile7 << v[i].getregnum() << ",";
					myfile7 << v[i].getlist()->getcost() << ",";
					//myfile3 << d[i].getage() << ",";
					//date pdate = c[i].getpDate();
					myfile7 << ptemp.getdate() << "," << ptemp.getmonth() << "," << ptemp.getyear() << ",";
					myfile7 << v[i].getoverallranking() << ",";
					//myfile3 << d[i].getoverallranking();
					myfile7 << "," << v[i].getstatus() << ",";
					myfile7 << v[i].getavgmileage() << ",";
					//myfile3 << d[i].getstatus() << ",";

					myfile7 << v[i].getlist()->getdescription() << ",";
					myfile7 << v[i].getlicencetype();

					myfile7 << endl;
				}
				myfile7.close();
			}
			////////////////////////////////


		}

		if (op == 4)//complete
		{

			for (int i = 0; i < customerCount; i++)
			{
				cout << "customer number " << i + 1 << endl;
				cout << c[i].getperson().getpName().getf() << " " << c[i].getperson().getpName().getl();
				cout << endl;
			}



		}

		if (op == 5)//complete
		{

			for (int i = 0; i < driverCount; i++)
			{
				cout << "driver number " << i + 1 << endl;
				cout << d[i].getperson().getpName().getf() << " " << d[i].getperson().getpName().getl();
				cout << endl;
			}



		}

		if (op == 6)//complete
		{
			cout << "ride vehicles = ";
			for (int i = 0; i < vehicleCount; i++)
			{
				string h = v[i].getlicencetype();

				if (h == "motorcar/jeep" || h == "motorbike/rickshaw" || h == "PSV")
				{
					cout << v[i];
				}
				cout << endl;
			}

			cout << "transport vehicles = ";
			for (int i = 0; i < vehicleCount; i++)
			{
				string h = v[i].getlicencetype();

				if (h == "LTV" || h == "HTV" || h == "Tractor")
				{
					cout << v[i];
				}
				cout << endl;

			}
		}

		if (op == 7)//complete
		{
			int vehicleid;
			int cou = 1;
			cout << "enter vehicle ID= ";
			cin >> vehicleid;

			for (int i = 0; i < vehicleCount; i++)
			{
				if (vehicleid == v[i].getvid())
				{


					/*cout << v[i];
					cout << endl;*/
					cout << "services done by vehicle = " << endl;

					for (int j = 0; j < rideCount1; j++)
					{


						if (vehicleid == rrr[j].getservice().getvi())
						{
							if (rrr[j].getff()==1) {

								cout << cou << ".";
								cout << rrr[j];
								cou++;

							}

						}
					}

					for (int k = 0; k < deliveryCount; k++)
					{
						if (vehicleid == dd[k].getservice().getvi())
						{

							if (dd[k].getff()==1)
							{
								cout << cou << ".";
								cout << dd[k];
								cou++;
							}

						}
					}

				}




			}


		}


		if (op == 8)//complete
		{

			int customerid;
			int cou = 1;
			cout << "enter customer ID= ";
			cin >> customerid;

			for (int i = 0; i < customerCount; i++)
			{
				if (customerid == c[i].getcid())
				{


					cout << c[i];
					cout << endl;
					cout << "services requested by the customer = " << endl;
					//cout << "services done by vehicle = " << endl;
					for (int j = 0; j < rideCount1; j++)
					{

						if (customerid == rrr[j].getservice().getci())
						{
							cout << cou << ".";
							cout << rrr[j];
							cou++;
						}
					}

					for (int k = 0; k < deliveryCount; k++)
					{
						if (customerid == dd[k].getservice().getci())
						{
							cout << cou << ".";
							cout << dd[k];
							cou++;
						}
					}

				}




			}




		}

		if (op == 9)///driver id print details including services//complete
		{
			int driverid;
			int cou = 1;
			cout << "enter driver ID= ";
			cin >> driverid;

			for (int i = 0; i < driverCount; i++)
			{
				if (driverid == d[i].getdid())
				{


					cout << d[i];
					cout << endl;
					cout << "services done by the driver = " << endl;
					//cout << "services done by vehicle = " << endl;
					for (int j = 0; j < rideCount1; j++)
					{
						//cout << "hi";

						if (driverid == rrr[j].getservice().getdi())
						{
							//cout << driverid;
							if (rrr[j].getff() == 1) {
								cout << "hi";
								cout << cou << ".";
								cout << rrr[j];
								cou++;


							}

						}
					}

					for (int k = 0; k < deliveryCount; k++)
					{
						if (driverid == dd[k].getservice().getdi())
						{
							if (dd[k].getff()== 1)
							{
								cout << cou << ".";
								cout << dd[k];
								cou++;
							}

						}
					}

				}




			}

		}

		if (op == 10)//list of drivers ranking above 4.5//complete
		{
			float ddd = 4.5;
			for (int i = 0; i < driverCount; i++)
			{
				if (d[i].getoverallranking() >= 4.5)
				{
					cout << d[i].getperson().getpName().getf() << " " << d[i].getperson().getpName().getl();;
				}
			}

		}

		if (op == 11)////giving garbage value on licesnce info///not complete
		{

			for (int i = 0; i < driverCount; i++)
			{
				if (d[i].getnooflicence() > 1)
				{
					cout << d[i].getperson();
					cout << d[i].getsll();
				}
			}


		}

		if (op == 12)//Print updated salary of all drivers based on their updated ranking.//yet to do
		{
			for (int i = 0; i < driverCount; i++)
			{
				if (d[i].getoverallranking()<d[i+1].getoverallranking())
				{
					cout <<d[i].getperson().getpName()<<" " << d[i].getsalary() << endl;
				}
				else {
					cout << d[i].getperson().getpName() << " " << d[i].getsalary() << endl;
				}
			}
		}

		if (op == 13)//Add a Service request."//complete
		{
			int customerid;
			cout << "enter customer id = ";
			cin >> customerid;

			int op3;
			cout << "1.ride service" << endl;
			cout << "2.delivery service" << endl;
			cout << "selected option = ";
			cin >> op3;

			if (op3 == 1)
			{
				if (rideCount1 < 100) {

					int numberofpass;
					char* type = new char[100];

					cout << "enter number of passengers = ";
					cin >> numberofpass;
					int uu;
					cout << "type of transportation =";
					cout << "1.intercity ";
					cout << "2.intracity ";
					cin >> uu;
					if (uu == 1)
					{
						string j = "intercity";
						char* temp = new char[9];
						for (int i = 0; i < 8; i++)
						{
							temp[i] = j[i];
						}
						temp[9] = '\0';
						type = temp;
						type[9] = '\0';
						delete[] temp;
					}
					else {
						string j = "intracity";
						char* temp = new char[10];
						for (int i = 0; i < 9; i++)
						{
							type[i] = j[i];
						}
						temp[10] = '\0';
						type = temp;
						type[10] = '\0';
						delete[] temp;
					}

					char* ss = new char[100];
					char* ddes = new char[100];
					int date1;
					int month;
					int year;
					int hrs;
					int mins;
					int sec;

					cout << "enter source = ";
					cin >> ss;

					int len = strlen(ss);
					//cout << len;
					ss[len + 1] = '\0';

					cout << "enter destination = ";
					cin >> ddes;

					int len1 = strlen(ddes);
					//cout << len1;
					ddes[len1 + 1] = '\0';

					float ddis;
					cout << "enter distance = ";
					cin >> ddis;
					cout << "enter date = ";
					cin >> date1;

					cout << "enter month = ";
					cin >> month;

					cout << "enter year = ";
					cin >> year;

					cout << "enter hr";
					cin >> hrs;
					cout << "enter mins";
					cin >> mins;
					cout << "enter seconds";
					cin >> sec;
					//cout << "";



					///output
					cout << "driver list";
					for (int i = 0; i < driverCount; i++)
					{
						if (d[i].getstatus() == 1 || d[i].getstatus() == 3)
						{
							cout << "Name= " << d[i].getperson().getpName().getf() << " " << d[i].getperson().getpName().getl() << endl;
							cout << "driver ID = " << d[i].getdid() << endl;
							cout << "ranking = " << d[i].getoverallranking();

						}


					}
					cout << "vehicle list" << endl;

					for (int i = 0; i < vehicleCount; i++)
					{

						if (v[i].getstatus() == true)
						{
							//	cout << "hi";

							cout << "vehicle ID = " << v[i].getvid() << endl;
							cout << "ranking = " << v[i].getoverallranking() << endl;
							cout << "fuel type = " << v[i].getfueltype() << endl;

						}


					}
					cout << endl;
					int edid, evid;
					cout << "select driver ID =";
					cin >> edid;
					cout << "select vehicle ID =";
					cin >> evid;

					for (int i = 0; i < driverCount; i++)
					{
						if (d[i].getdid() == edid)
						{
							d[i].setdid(2);


						}
					}
					int index;

					for (int i = 0; i < vehicleCount; i++)
					{
						if (v[i].getvid() == evid)
						{
							index = i;
							v[i].setvid(false);



						}

					}
					//petrol 150
					//disel 100
					float fair = 0;
					//cout << index;
					string er = v[index].getfueltype();
					//cout << er;
					float rate = 0;
					if (er == "petrol")
					{
						rate = 150;
						fair = 150 * ddis;
					}
					else if (er == "disel") {
						rate = 100;
						fair = 100 * ddis;
					}
					cout << "total fair= " << fair;

					ride xx;
					service kk;
					date ll(date1, month, year);
					mtime mm(hrs, mins, sec);
					kk.setci(customerid);
					kk.setdi(edid);
					kk.setdestination(ddes);
					kk.setsource(ss);
					kk.setserdate(ll);
					kk.setvi(evid);
					kk.setstatus(false);
					kk.setfulerate(rate);
					kk.setsertime(mm);
					kk.setdistance(ddis);

					xx.setff(2);
					xx.setservice(kk);
					xx.setpassengers(numberofpass);
					xx.setridetype(type);
					xx.setdriverrank(0);
					xx.setvehiclerank(0);

					//service* temp = new ride();


					rrr[rideCount1] = xx;
					rideCount1++;



					delete[]type;
					delete[] ddes;
					delete[] ss;

				}

				else { cout << "ride capacity full. "; }

				fstream myfile8;
				myfile8.open("rideservice.txt", ios::out);
				if (!myfile8) {
					cout << "File not created!";
				}
				else {
					//cout << "File created successfully!";
					for (int i = 0; i < rideCount1; i++) {
						myfile8 << rrr[i].getservice().getsource() << ",";
						myfile8 << rrr[i].getservice().getdestination() << ",";
						myfile8 << rrr[i].getservice().getdistance() << ",";
						myfile8 << rrr[i].getservice().getserdate().getdate() << "," << rrr[i].getservice().getserdate().getmonth() << "," << rrr[i].getservice().getserdate().getyear() << ",";
						myfile8 << rrr[i].getservice().getsertime().gethrs() << "," << rrr[i].getservice().getsertime().getmins() << "," << rrr[i].getservice().getsertime().getsecs() << ",";
						myfile8 << rrr[i].getservice().getstatus() << ",";
						myfile8 << rrr[i].getservice().getfuelrate() << ",";
						myfile8 << rrr[i].getservice().getci() << ",";
						myfile8 << rrr[i].getservice().getdi() << ",";
						myfile8 << rrr[i].getservice().getvi() << ",";
						myfile8 << rrr[i].getpassensgers() << ",";
						myfile8 << rrr[i].getridetype() << ",";
						myfile8 << rrr[i].getdriverank() << ",";
						myfile8 << rrr[i].getvehicleank() << endl;



					}
					myfile8.close();
				}






			}



			if (op3 == 2)
			{
				if (deliveryCount < 100) {

					float goodweight;
					char* type = new char[100];

					cout << "enter weight = ";
					cin >> goodweight;
					int uu = 0;
					cout << "type of goods =";
					cin >> type;

					//string j = "intercity";
					int llen = strlen(type);
					type[llen + 1] = '\0';

					char* ss = new char[100];
					char* ddes = new char[100];
					int date1;
					int month;
					int year;
					int hrs;
					int mins;
					int sec;

					cout << "enter source = ";
					cin >> ss;

					int len = strlen(ss);
					//cout << len;
					ss[len + 1] = '\0';

					cout << "enter destination = ";
					cin >> ddes;

					int len1 = strlen(ddes);
					//cout << len1;
					ddes[len1 + 1] = '\0';

					float ddis;
					cout << "enter distance = ";
					cin >> ddis;
					cout << "enter date = ";
					cin >> date1;

					cout << "enter month = ";
					cin >> month;

					cout << "enter year = ";
					cin >> year;

					cout << "enter hr";
					cin >> hrs;
					cout << "enter mins";
					cin >> mins;
					cout << "enter seconds";
					cin >> sec;
					//cout << "";



					///output
					cout << "driver list";
					for (int i = 0; i < driverCount; i++)
					{
						if (d[i].getstatus() == 1 || d[i].getstatus() == 3)
						{
							cout << "Name= " << d[i].getperson().getpName().getf() << " " << d[i].getperson().getpName().getl() << endl;
							cout << "driver ID = " << d[i].getdid() << endl;
							cout << "ranking = " << d[i].getoverallranking();

						}


					}
					cout << "vehicle list" << endl;

					for (int i = 0; i < vehicleCount; i++)
					{

						if (v[i].getstatus() == true)
						{
							//	cout << "hi";

							cout << "vehicle ID = " << v[i].getvid() << endl;
							cout << "ranking = " << v[i].getoverallranking() << endl;
							cout << "fuel type = " << v[i].getfueltype() << endl;

						}


					}
					cout << endl;
					int edid, evid;
					cout << "select driver ID =";
					cin >> edid;
					cout << "select vehicle ID =";
					cin >> evid;

					for (int i = 0; i < driverCount; i++)
					{
						if (d[i].getdid() == edid)
						{
							d[i].setdid(2);


						}
					}
					int index;

					for (int i = 0; i < vehicleCount; i++)
					{
						if (v[i].getvid() == evid)
						{
							index = i;
							v[i].setvid(false);



						}

					}
					//petrol 150
					//disel 100
					float fair = 0;
					//cout << index;
					string er = v[index].getfueltype();
					//cout << er;
					float rate = 0;
					if (er == "petrol")
					{
						rate = 150;
						fair = 150 * ddis;
					}
					else if (er == "disel") {
						rate = 100;
						fair = 100 * ddis;
					}
					cout << "total fair= " << fair;

					delivery xx;
					service kk;
					date ll(date1, month, year);
					mtime mm(hrs, mins, sec);
					kk.setci(customerid);
					kk.setdi(edid);
					kk.setdestination(ddes);
					kk.setsource(ss);
					kk.setserdate(ll);
					kk.setvi(evid);
					kk.setstatus(false);
					kk.setfulerate(rate);
					kk.setsertime(mm);
					kk.setdistance(ddis);

					xx.setff(2);
					xx.setservice(kk);
					xx.setgoodweight(goodweight);
					xx.setgoodstype(type);
					xx.setdriverrank(0);
					xx.setvehiclerank(0);

					//service* temp = new ride();


					dd[deliveryCount] = xx;
					deliveryCount++;


					delete[]type;
					delete[] ddes;
					delete[] ss;

				}

				else { cout << "ride capacity full. "; }

				fstream myfile9;
				myfile9.open("deliveryservice.txt", ios::out);
				if (!myfile9) {
					cout << "File not created!";
				}
				else {
					//cout << "File created successfully!";
					for (int i = 0; i < deliveryCount; i++) {
						myfile9 << dd[i].getservice().getsource() << ",";
						myfile9 << dd[i].getservice().getdestination() << ",";
						myfile9 << dd[i].getservice().getdistance() << ",";
						myfile9 << dd[i].getservice().getserdate().getdate() << "," << rrr[i].getservice().getserdate().getmonth() << "," << rrr[i].getservice().getserdate().getyear() << ",";
						myfile9 << dd[i].getservice().getsertime().gethrs() << "," << rrr[i].getservice().getsertime().getmins() << "," << rrr[i].getservice().getsertime().getsecs() << ",";
						myfile9 << dd[i].getservice().getstatus() << ",";
						myfile9 << dd[i].getservice().getfuelrate() << ",";
						myfile9 << dd[i].getservice().getci() << ",";
						myfile9 << dd[i].getservice().getdi() << ",";
						myfile9 << dd[i].getservice().getvi() << ",";
						myfile9 << dd[i].getgoodsweight() << ",";
						myfile9 << dd[i].getgoodstype() << ",";
						myfile9 << dd[i].getdriverank() << ",";
						myfile9 << dd[i].getvehicleank() << endl;



					}
					myfile9.close();
				}






			}









		}

		if (op == 14)//Cancel a booking.
		{
			int customrid;
			cout << "enter customer id = ";
			cin >> customrid;
			int op5 = 0;
			cout << "1.cancel ride delivery.";
			cout << "2.cancel delivery ride.";
			cin >> op5;
			if (op5 == 1)
			{
				cout << "select ride you want to cancel." << endl;
				int* inn = new int[20];
				int ccc = 0;
				for (int i = 0; i < rideCount1; i++)
				{
					if (customrid == rrr[i].getservice().getci())
					{
						if (rrr[i].getservice().getstatus() == false)

						{
							cout << ccc + 1 << ".";
							inn[ccc] = i;
							cout << rrr[i];
							++ccc;
						}



					}

				}
				//cout << inn[1];

				int index = 0;
				cin >> index;
				int index1 = inn[index - 1];
				//cout << index1;
				//cout << ccc;
				int cccc = 0;
				service b;
				for (int i = 0; i < rideCount1; i++)
				{
					if (i == index1)
					{
						int di, vi;
						di = rrr[i].getservice().getdi();
						vi = rrr[i].getservice().getvi();

						//cout << di << vi;
						b = rrr[i].getservice();
						rrr[i].getservice().setvi(0);
					

						int jj = rrr[i].getservice().getdi();
						//cout << jj;
						for (int j = 0; j < driverCount; j++)
						{
							if (di == d[j].getdid())
							{
								d[j].setstatus(3);
							}
						}

						for (int j = 0; j < vehicleCount; j++)
						{
							if (vi == v[j].getvid())
							{
								v[j].setstatus(false);
							}
						}

					}
				}
				//cout << rrr[index1].getservice().getdi();
				/*cout << b.getdi();
				cout << b.getdi();*/

				b.setdi(0);
				b.setvi(0);

				/*	cout << b.getdi();
				cout << b.getdi();*/
				rrr[index1].setservice(b);
				rrr[index1].setff(3);
				cout << rrr[index1].getservice().getdi();
				cout << "cancellation fee = ";
				cout << (rrr[index1].getservice().getfuelrate()) * 0.5;


				delete[] inn;

			}

			if (op5 == 2)
			{
				cout << "select delivery you want to cancel." << endl;
				int* inn = new int[20];
				int ccc = 0;
				for (int i = 0; i < deliveryCount; i++)
				{
					if (customrid == dd[i].getservice().getci())
					{
						if (dd[i].getservice().getstatus() == false)

						{
							cout << ccc + 1 << ".";
							inn[ccc] = i;
							cout << dd[i];
							++ccc;
						}



					}

				}
				//cout << inn[1];

				int index = 0;
				cin >> index;
				int index1 = inn[index - 1];
				//cout << index1;
				//cout << ccc;
				int cccc = 0;
				service g;
				for (int i = 0; i < deliveryCount; i++)
				{
					if (i == index1)
					{
						int di, vi;
						di = dd[i].getservice().getdi();
						vi = dd[i].getservice().getvi();
						g = dd[index1].getservice();

						//cout << di << vi;
						dd[i].getservice().setdi(0);
						dd[i].getservice().setvi(0);

						for (int j = 0; j < driverCount; j++)
						{
							if (di == d[j].getdid())
							{
								//cout << d[j].getstatus();
								d[j].setstatus(3);
								//cout << d[j].getstatus();
							}
						}

						for (int j = 0; j < vehicleCount; j++)
						{
							if (vi == v[j].getvid())
							{
								v[j].setstatus(false);
							}
						}

					}
				}
				g.setdi(0);
				g.setvi(0);

				dd[index1].setservice(g);
				dd[index1].setff(3);
				cout << "cancellation fee = ";
				cout << (dd[index1].getservice().getfuelrate()) * 0.5;


				delete[] inn;

			}



		}

		if (op == 15)//Complete a service
		{
			int cuu;
			cout << "enter customer ID= ";
			cin >> cuu;
			int op3;
			cout << "1.ride service" << endl;
			cout << "2.delivery service" << endl;
			cout << "selected option = ";
			cin >> op3;
			if (op3 == 1)
			{
				cout << "select ride you want to complete." << endl;
				int* inn = new int[20];
				int ccc = 0;
				for (int i = 0; i < rideCount1; i++)
				{
					if (cuu == rrr[i].getservice().getci())
					{
						if (rrr[i].getservice().getstatus() == false)

						{
							cout << ccc + 1 << ".";
							inn[ccc] = i;
							cout << rrr[i];
							++ccc;
						}



					}

				}

				//int index1;
				int index = 0;
				cin >> index;
				int index1 = inn[index - 1];
				//cout << index1;
				//cout << ccc;
				int cccc = 0;


				service ff;
				for (int i = 0; i < rideCount1; i++)
				{
					if (i == index1)
					{
						int di4, vi4;
						di4 = rrr[i].getservice().getdi();
						vi4 = rrr[i].getservice().getvi();

						ff = rrr[i].getservice();
						//int jj = rrr[i].getservice().getdi();
						//cout << jj;

						/*rrr[i].setdriverrank(drirank);
						rrr[i].setvehiclerank(vehrank);*/

						for (int j = 0; j < driverCount; j++)
						{
							if (di4 == d[j].getdid())
							{
								d[j].setstatus(1);
							}
						}

						for (int j = 0; j < vehicleCount; j++)
						{
							if (vi4 == v[j].getvid())
							{
								v[j].setstatus(1);
							}
						}


						//cout << rrr[i];
					}



				}
				//cout << rrr[index1].getdriverank();
				float drirank = 0, vehrank = 0;
				cout << "enter driver ranking = ";
				cin >> drirank;
				cout << "enter vehicle ranking = ";
				cin >> vehrank;
				ff.setstatus(true);
				rrr[index1].setservice(ff);

				rrr[index1].setdriverrank(drirank);
				rrr[index1].setvehiclerank(vehrank);
				//cout<<rrr[index1].getdriverank();
				//cout << rrr[index1].getservice().getstatus();;
				delete[] inn;
			}


			if (op3 == 2)
			{
				cout << "select delivery you want to complete." << endl;
				int* inn = new int[20];
				int ccc = 0, ccount = 0;
				for (int i = 0; i < deliveryCount; i++)
				{
					if (cuu == dd[i].getservice().getci())
					{
						if (dd[i].getservice().getstatus() == false)

						{
							++ccount;
							cout << ccc + 1 << ".";
							inn[ccc] = i;
							cout << dd[i];
							++ccc;
						}



					}

				}
				if (ccount == 0)
				{
					cout << "no pending delivery services available." << endl;
				}

				//int index1;
				int index = 0;
				cin >> index;
				int index1 = inn[index - 1];
				//cout << index1;
				//cout << ccc;
				int cccc = 0;


				service fff;
				for (int i = 0; i < deliveryCount; i++)
				{
					if (i == index1)
					{
						int di4, vi4;
						di4 = dd[i].getservice().getdi();
						vi4 = dd[i].getservice().getvi();

						fff = dd[i].getservice();
						//int jj = rrr[i].getservice().getdi();
						//cout << jj;

						/*rrr[i].setdriverrank(drirank);
						rrr[i].setvehiclerank(vehrank);*/

						for (int j = 0; j < driverCount; j++)
						{
							if (di4 == d[j].getdid())
							{
								d[j].setstatus(1);
							}
						}

						for (int j = 0; j < vehicleCount; j++)
						{
							if (vi4 == v[j].getvid())
							{
								v[j].setstatus(1);
							}
						}


						//cout << rrr[i];
					}



				}
				//cout << rrr[index1].getdriverank();
				float drirank = 0, vehrank = 0;
				cout << "enter driver ranking = ";
				cin >> drirank;
				cout << "enter vehicle ranking = ";
				cin >> vehrank;
				fff.setstatus(true);
				dd[index1].setservice(fff);

				dd[index1].setdriverrank(drirank);
				dd[index1].setvehiclerank(vehrank);
				//cout<<rrr[index1].getdriverank();
				//cout << rrr[index1].getservice().getstatus();;
				cout << endl;
				delete[] inn;
			}










		}
		if (op == 16)
		{
			int cus = -1;
			int vehicleid;
			cout << "enter vehicle id= ";
			cin >> vehicleid;
			int hh = 0;
			int* aa = new int[hh];
			cout << rideCount1;
			for (int i = 0; i < rideCount1; i++)
			{


				if (vehicleid == rrr[i].getservice().getvi())
				{

					//cout << i;
					aa[hh] = i;
					//cout << i;
					hh++;
				}

				//}

			}
			//aa[hh + 1] = '\0';
			//cout << aa[hh];

			int h = 0;
			int d1 = 0, d2 = 0;
			for (int i = 0; i < hh; i++)
			{
				if (i < hh)
				{
					d1 = rrr[aa[i]].getservice().getserdate().getdate();
					d2 = rrr[aa[i + 1]].getservice().getserdate().getdate();
					//cout << d1;
					//cout << d2;
					//cout << endl;
					if (d1 != d2)
					{
						cout << c[aa[i]].getperson().getpName().getf() << " " << c[aa[i]].getperson().getpName().getl() << endl;
					}
					if (d1 == d2)
					{
						aa[i + 1] == aa[i + 2];
					}
					d1 = 0;
					d2 = 0;
				}
				if (i == hh)
				{

					d2 = rrr[aa[i + 1]].getservice().getserdate().getdate();
					cout << c[aa[i]].getperson().getpName().getf() << " " << c[aa[i]].getperson().getpName().getl() << endl;
				}




			}

			//delete[]aa;

		}
		if (op == 17)//Print the List of all Drivers who completed delivery services on same days.
		{
			int del,min,yyr;
			cout << "enter date = ";
			cin >> del;
			cout << "enter month = ";
			cin >> min;
			cout << "enter year = ";
			cin >> yyr;
			date no(del, min, yyr);
			for (int i = 0; i < deliveryCount; i++)
			{
				if (dd[i].getservice().getserdate().getdate()== del  && dd[i].getservice().getserdate().getmonth() == min && dd[i].getservice().getserdate().getyear() == yyr)
				{
					if (dd[i].getservice().getstatus() == true && dd[i].getff()!=3 && dd[i].getff()!=2)
					{

						cout << d[i].getperson().getpName().getf() << " " << d[i].getperson().getpName().getf();
					}
				}
				
			}

		}
		if (op == 18)//pending services is false//Print details of all pending services on a particular date.
		{

			int date1;
			cout << "enter date = ";
			cin >> date1;
			int in;
			for (int i = 0; i < rideCount1; i++)
			{

				if (date1 == rrr[i].getservice().getserdate().getdate())
				{
					//cout << "hi";
					in = i;
					if (rrr[in].getservice().getstatus() == false && rrr[in].getff()==2)
					{
						cout << rrr[i];
					}
				}
			}
			for (int i = 0; i < deliveryCount; i++)
			{

				if (date1 == dd[i].getservice().getserdate().getdate())
				{
					//cout << "hi";
					in = i;
					if (dd[in].getservice().getstatus() == false && dd[in].getff() == 2)
					{
						cout << dd[i];
					}
				}
			}

		}
		if (op == 19)//Print details of all pending services of a particular driver.
		{
			int date1;
			cout << "enter driver ID = ";
			cin >> date1;
			int in;
			for (int i = 0; i < deliveryCount; i++)
			{
				if (date1 == dd[i].getservice().getdi()) {

					in = i;

					if (dd[i].getservice().getstatus() == false && dd[i].getff() == 2)
					{
						cout << dd[i];
					}



				}




			}
			for (int i = 0; i < rideCount1; i++)
			{
				if (date1 == rrr[i].getdi()) {

					in = i;

					if (rrr[i].getservice().getstatus() == false && rrr[i].getff() == 2)
					{
						cout << rrr[i];
					}



				}




			}

		}
		if (op == 20)//Print details of all canceled services by a customer.
		{

			//driver status 3 if canceled

			int cusid;
			cout << "enter customer ID= ";
			cin >> cusid;


			int dri;
			for (int i = 0; i < rideCount1; i++)
			{

				if (cusid == rrr[i].getservice().getci() && rrr[i].getff() == 3)
				{

					dri = rrr[i].getservice().getdi();

					for (int j = 0; j < driverCount; j++)
					{


						if (dri == d[j].getdid())
						{
							//cout << "hi";
							/*if (d[j].getstatus() == 3)
							{*/
							//cout << "hi";
							cout << rrr[i];
							//}
						}


					}
				}
			}
			for (int i = 0; i < deliveryCount; i++)
			{

				if (cusid == dd[i].getservice().getci() && dd[i].getff() == 3)
				{

					dri = dd[i].getservice().getdi();

					for (int j = 0; j < driverCount; j++)
					{


						if (dri == d[j].getdid())
						{
							//cout << "hi";
							/*if (d[j].getstatus() == 3)
							{*/
							//cout << "hi";
							cout << dd[i];
							//}
						}


					}






				}




			}
		}
		if (op == 21)
		{
			op = -1;
		}

	}






	return 0;
}