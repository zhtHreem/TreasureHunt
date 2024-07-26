#include<iostream>
#include <string.h>
#include <string>
#include <fstream>
#include<ctime>
#include <conio.h>
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27


template<class T>
class stackList {
private:
	struct Node {
	public:
		Node() {
			next = NULL;
		}
		Node(T value, Node* ptr = 0) {
			data = value;
			next = ptr;
		}
		T data;
		Node* next;
	};
	Node* head, * tail;
	int size;

public:
	stackList() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	bool push(T val) {
		bool found = false;
		if (head != NULL) {
			head = new Node(val, head);
			found = true;
		}
		else {
			head = tail = new Node(val, head);
			found = true;
		}
		return found;
	}
	bool pop() {
		bool found = false;
		if (head != NULL) {
			Node* temp;
			if (head == tail) {             //One value

				head = tail = NULL;
				found = true;
			}
			else {
				temp = head;               //points toward current value
				head = head->next;         // points toward next value
				temp = NULL;
				found = true;
			}
		}
		return found;
	}

	void Print() {
		Node* temp = head;
		for (temp = head; temp != NULL; temp = temp->next)
		{
			cout << temp->data << " ";
		}
		cout << endl;
	}
	T Top() {
		/*if (head == NULL) {
			return -1;
		}
		else {*/
		T temp = head->data;
		return temp;
		//}
	}
	int sizes() {
		Node* temp = head;
		int count = 0;
		while (temp != NULL) {
			count++;
			temp = temp->next;
		}

		return count;
	}
	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	bool isFull() {
		if (head != NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	void recur(stackList<T> obj, int size, T top) {          //Recursive function
		int s;

		top = obj.Top();

		if (size >= 1) {
			obj.pop();
		}

		if (size == 0) {

			cout << top << endl;;
			obj.pop();
		}
		else {
			s = obj.sizes() - 1;
			recur(obj, s, top);
			cout << top;
			cout << endl;
			obj.pop();
		}


	}
	~stackList() {
		Node* temp = NULL;
		while (head != NULL) {
			temp = head;
			head = head->next;
			temp = NULL;
		}
	}
};

class rooms {
private:
	int numOfRows, numOfColumns;
	int x, y, roomNumber, currentPos, r, c, Treasure;
	char** map;
public:
	rooms() {
		numOfRows = 0;
		numOfColumns = 0;
		x = 0;
		y = 0;
		roomNumber = 0;
		currentPos = 0;
		Treasure = 0;
		c = 0;
		r = 0;
	}
	void setNumOfRows(int row) {
		numOfRows = row;
	}
	int getNumOfRows() {
		return numOfRows;
	}

	void setNumOfColumns(int col) {
		numOfColumns = col;
	}
	int getNumOfColumns() {
		return numOfColumns;
	}

	void setx(int _x) {
		x = _x;
	}
	int getx() {
		return x;
	}

	void setroomno(int _x) {
		currentPos = _x;
	}
	int getroomno() {
		return currentPos;
	}
	void sety(int _y) {
		y = _y;
	}
	int gety() {
		return y;
	}

	void setr(int _r) {
		r = _r;
	}
	int getr() {
		return r;
	}

	void setc(int _c) {
		c = _c;
	}
	int getc() {
		return c;
	}
	void setT(int _t) {
		Treasure = _t;
	}
	int getT() {
		return Treasure;
	}
	void _map(int i, int j, char read) {
		map[i][j] = read;
	}
	char getmap(int i, int j) {
		return map[i][j];
	}

	void declaresize(int row, int col) {  //declaring matrix size
		map = new char* [row];
		for (int i = 0; i < row; i++) {
			map[i] = new char[col];
		}
	}

	int number(int m) { // file reading storing coordinates
		int ret;
		if (m == 48) { return ret = 0; }
		else if (m == 49) { return ret = 1; }
		else if (m == 50) { return ret = 2; }
		else if (m == 51) { return ret = 3; }
		else if (m == 52) { return ret = 4; }
		else if (m == 53) { return ret = 5; }
		else if (m == 54) { return ret = 6; }
		else if (m == 55) { return ret = 7; }
		else if (m == 56) { return ret = 8; }
		else if (m == 57) { return ret = 9; }

	}
	void updatematrix(int& row, int& col, int totalRows, int totalCols, int& roomno, int& key, int& g, int& Tkey, int totalrooms) {
		system("cls");

		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "+   ________    ________    ________    _________   ________   +\n";
		cout << "+  |        |  |        |  |        |  |         | |        |  +\n";
		cout << "+  |  -------   ---  ---   |   /\\   |  |   |\\    |  ---  ---   +\n";
		cout << "+  |  |           |  |     |  |  |  |  |   | \\   |    |  |     +\n";
		cout << "+  |  -----       |  |     |  |  |  |  |   |  /  /    |  |     +\n";
		cout << "+  |        |     |  |     |  |__|  |  |   | /  /     |  |     +\n";
		cout << "+   -----   |     |  |     |        |  |   | \\  \\     |  |     +\n";
		cout << "+       |   |     |  |     |  |--|  |  |   |  |  |    |  |     +\n";
		cout << "+   -----   |     |  |     |  |  |  |  |   |  |  |    |  |     +\n";
		cout << "+  |        |     |  |     |  |  |  |  |   |  |  |    |  |     +\n";
		cout << "+   ---------     ----     ----  ----  ----    ----   ----     +\n";
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

		cout << "\t\t PRESS ESC TO END THE GAME \t\t\n\n";
		cout << "\n\t\t\t   ----------------------" << endl;
		for (int i = 0; i < totalRows; i++) {
			cout << "\t\t\t  " << " | ";

			for (int j = 0; j < totalCols; j++) {
				if (i == row && j == col) {
					if (map[i][j] == 'P') {
						bool found = portal(roomno, key, totalrooms);
					}
					else if (map[i][j] == 'D' || map[i][j] == 'X') { /////
						key = 27;
					}
					else if (map[i][j] == 'T') {
						Tkey = 2;
					}
					else if (map[i][j] == 'G') { //Gasper
						g = 1;
					}
					cout << "*";

				}
				else { cout << map[i][j]; } // " "
				cout << "  ";
			}
			cout << " | ";
			cout << endl;
		}
		cout << "\t\t\t   ----------------------" << endl;
	}

	bool portal(int& roomno, int& key, int& totalrooms) {
		//srand(time(0));
		int head = rand() % totalrooms;
		bool found = false;
		if (!head) {  ///tail
			if (roomno > 0) {
				roomno--;
			}
			else {
				key = 27;
			}
			found = true;
		}
		else {
			roomno = rand() % totalrooms;
			found = true;
		}
		return found;
	}
	friend ostream& operator<< (ostream& cout, rooms& obj) {

		cout << "Room No: " << obj.getroomno() << endl;
		cout << "\n\t\t\t\t   ----------------------" << endl;
		for (int i = 0; i < obj.getNumOfRows(); i++) {
			cout << "\t\t\t\t  " << " | ";
			for (int j = 0; j < obj.getNumOfColumns(); j++) {
				if (i == obj.getr() && j == obj.getc())
				{
					cout << "*";
				}
				else {
					cout << obj.getmap(i, j);
				}
				cout << "   ";
			}
			cout << " | ";
			cout << endl;
		}
		cout << "\t\t\t\t   ----------------------" << endl;
		cout << endl;
		return cout;

	}
	~rooms() {
		/*	for (int i = 0; i < numOfRows; i++) {
				delete[] map[i];
			}
			delete[] map;*/
	}
};

class coordinates {
private:
	int x, y, noOfrooms, currentRoom;
public:
	coordinates() {
		x = 0;
		y = 0;
		noOfrooms = 0;
		currentRoom = 0;


	}
	void setnoOfRooms(int _x) {
		noOfrooms = _x;
	}
	int getnoOfRooms() {
		return noOfrooms;
	}
	void setcurrentRoom(int _x) {
		currentRoom = _x;
	}
	int getcurrentRoom() {
		return currentRoom;
	}
	void setx(int _x) {
		x = _x;
	}
	int getx() {
		return x;
	}
	void sety(int _x) {
		y = _x;
	}
	int gety() {
		return y;
	}

	friend ostream& operator<< (ostream& cout, coordinates& obj) {

		cout << " (" << obj.getx() << "," << obj.gety() << ")  Room:" << obj.getcurrentRoom();
		return cout;

	}

};
class hauntedHouse {
private:
	int numOfRooms;
	int currentroom;
	coordinates cor;
	stackList<coordinates> coordinate;
	stackList<rooms> roommap;


	rooms* room;
public:
	hauntedHouse() {
		numOfRooms = 0;
		currentroom = 0;
		room = new rooms[numOfRooms]; //
	//	coordinate = NULL;
	}

	void setnumOfRooms(int _x) {
		numOfRooms = _x;
	}
	int getnumOfRooms() {
		return numOfRooms;
	}
	void setRooms(rooms _x) {
		room[currentroom] = _x;
		currentroom++;
	}


	void Print() {
		system("cls");
		int totalrooms = numOfRooms;
		int key = 0, currentroomno = 0, prevroomno = 0, gasper = 0, save = 0, treasure = 0, Tkey = 0;
		int f = 1;
		int x = room[currentroomno].getx(), y = room[currentroomno].gety();
		room[currentroomno].updatematrix(x, y, room[currentroomno].getNumOfRows(), room[currentroomno].getNumOfColumns(), currentroomno, key, gasper, Tkey, totalrooms);
		room[currentroomno].setroomno(currentroomno);
		room[currentroomno].setr(x);
		room[currentroomno].setc(y);


		cor.setx(x);
		cor.sety(y);
		cor.setcurrentRoom(currentroomno);

		coordinate.push(cor);

		roommap.push(room[currentroomno]);


		while (1)
		{

			switch ((key = _getch()))
			{
			case KEY_UP:

				if (x > 0) x = x - 1;
				room[currentroomno].updatematrix(x, y, room[currentroomno].getNumOfRows(), room[currentroomno].getNumOfColumns(), currentroomno, key, gasper, Tkey, totalrooms); //Updates the map
				cor.setx(x);                                                                            // set row in coordinates class
				cor.sety(y);
				cor.setcurrentRoom(currentroomno);                                                      //set row in coordinate class
				coordinate.push(cor);                                                                   //push it in stack<coordinate>

				room[currentroomno].setr(x);
				room[currentroomno].setc(y);
				roommap.push(room[currentroomno]);                                                     // stack<rooms>    roommap is pushed

				if (key == 27) {                                                                       //if the player steps on X || D
					cout << "Game ended";
					exit(0);
				}
				if (Tkey == 2) {                                                                        //If the key is found 
					cout << "Treasure is found\n";
					cout << " Iterative: \n";
					coordinate.Print();
					roommap.Print();
					cout << " Recursion: \n";
					recurcoordinate(coordinate, coordinate.sizes(), coordinate.Top());
					recurroom(roommap, roommap.sizes(), roommap.Top());
					exit(0);
				}
				if (gasper == 1) {                                                                     // Teleport to room with treasure                                  
					for (int i = 0; i < getnumOfRooms(); i++) {                                        // i<totalnuumberofrooms
						treasure = room[i].getT();
						if (treasure == 1) {
							save = i;
						}
					}
					currentroomno = save;
				}


				if (currentroomno != prevroomno) {                                                   //When player use portal or comes in contact with gasper
					prevroomno = currentroomno;
					x = room[currentroomno].getx(), y = room[currentroomno].gety();
					//
					x = rand() % room[currentroomno].getNumOfRows();
					y = rand() % room[currentroomno].getNumOfColumns();
					while (room[currentroomno].getmap(x, y) == 'X' || room[currentroomno].getmap(x, y) == 'D') {
						srand(time(0));
						x = rand() % room[currentroomno].getNumOfRows();
						y = rand() % room[currentroomno].getNumOfColumns();
					}
					//

					room[currentroomno].updatematrix(x, y, room[currentroomno].getNumOfRows(), room[currentroomno].getNumOfColumns(), currentroomno, key, gasper, Tkey, totalrooms);
					cor.setx(x);
					cor.sety(y);
					cor.setcurrentRoom(currentroomno);

					coordinate.push(cor);


					room[currentroomno].setroomno(currentroomno);
					room[currentroomno].setr(x);
					room[currentroomno].setc(y);
					roommap.push(room[currentroomno]);

				}
				break;


			case KEY_DOWN:




				if (x < room[currentroomno].getNumOfRows() - 1) x = x + 1;
				room[currentroomno].updatematrix(x, y, room[currentroomno].getNumOfRows(), room[currentroomno].getNumOfColumns(), currentroomno, key, gasper, Tkey, totalrooms);
				cor.setx(x);
				cor.sety(y);
				cor.setcurrentRoom(currentroomno);
				coordinate.push(cor);

				room[currentroomno].setroomno(currentroomno);
				room[currentroomno].setr(x);
				room[currentroomno].setc(y);
				roommap.push(room[currentroomno]);

				if (key == 27) {
					cout << "Game ended";
					exit(0);
				}
				if (Tkey == 2) {
					cout << "Treasure is found\n";
					cout << " Iterative: \n";
					coordinate.Print();
					roommap.Print();
					cout << " Recursion: \n";
					recurcoordinate(coordinate, coordinate.sizes(), coordinate.Top());
					recurroom(roommap, roommap.sizes(), roommap.Top());
					exit(0);
				}
				if (gasper == 1) {
					for (int i = 0; i < 2; i++) {  // i<totalnuumberofrooms
						treasure = room[i].getT();
						if (treasure == 1) {
							save = i;
						}
					}
					currentroomno = save;

				}

				if (currentroomno != prevroomno) {
					prevroomno = currentroomno;
					x = room[currentroomno].getx(), y = room[currentroomno].gety();
					//
					srand(time(0));

					x = rand() % room[currentroomno].getNumOfRows();
					y = rand() % room[currentroomno].getNumOfColumns();
					while (room[currentroomno].getmap(x, y) == 'X' || room[currentroomno].getmap(x, y) == 'D') {
						srand(time(0));
						x = rand() % room[currentroomno].getNumOfRows();
						y = rand() % room[currentroomno].getNumOfColumns();
					}
					//

					room[currentroomno].updatematrix(x, y, room[currentroomno].getNumOfRows(), room[currentroomno].getNumOfColumns(), currentroomno, key, gasper, Tkey, totalrooms);
					cor.setx(x);
					cor.sety(y);
					cor.setcurrentRoom(currentroomno);

					coordinate.push(cor);


					room[currentroomno].setroomno(currentroomno);
					room[currentroomno].setr(x);
					room[currentroomno].setc(y);
					roommap.push(room[currentroomno]);

				}
				break;



			case KEY_LEFT:



				if (y > 0) y = y - 1;
				room[currentroomno].updatematrix(x, y, room[currentroomno].getNumOfRows(), room[currentroomno].getNumOfColumns(), currentroomno, key, gasper, Tkey, totalrooms);
				cor.setx(x);
				cor.sety(y);
				cor.setcurrentRoom(currentroomno);
				coordinate.push(cor);


				room[currentroomno].setroomno(currentroomno);
				room[currentroomno].setr(x);
				room[currentroomno].setc(y);
				roommap.push(room[currentroomno]);

				if (key == 27) {
					cout << "Game ended";
					exit(0);
				}
				if (Tkey == 2) {
					cout << "Treasure is found\n";
					cout << " Iterative: \n";
					coordinate.Print();
					roommap.Print();
					cout << " Recursion: \n";
					recurcoordinate(coordinate, coordinate.sizes(), coordinate.Top());
					recurroom(roommap, roommap.sizes(), roommap.Top());
					exit(0);
				}
				if (gasper == 1) {
					for (int i = 0; i < 2; i++) {  // i<totalnuumberofrooms
						treasure = room[i].getT();
						if (treasure == 1) {
							save = i;
						}
					}
					currentroomno = save;

				}
				if (currentroomno != prevroomno) {
					prevroomno = currentroomno;
					x = room[currentroomno].getx(), y = room[currentroomno].gety();

					//
					x = rand() % room[currentroomno].getNumOfRows();
					y = rand() % room[currentroomno].getNumOfColumns();
					while (room[currentroomno].getmap(x, y) == 'X' || room[currentroomno].getmap(x, y) == 'D') {
						srand(time(0));
						x = rand() % room[currentroomno].getNumOfRows();
						y = rand() % room[currentroomno].getNumOfColumns();
					}
					//

					room[currentroomno].updatematrix(x, y, room[currentroomno].getNumOfRows(), room[currentroomno].getNumOfColumns(), currentroomno, key, gasper, Tkey, totalrooms);
					cor.setx(x);
					cor.sety(y);
					cor.setcurrentRoom(currentroomno);
					coordinate.push(cor);


					room[currentroomno].setroomno(currentroomno);
					room[currentroomno].setr(x);
					room[currentroomno].setc(y);
					roommap.push(room[currentroomno]);

				}
				break;




			case KEY_RIGHT:



				if (y < room[currentroomno].getNumOfColumns() - 1) y = y + 1;
				room[currentroomno].updatematrix(x, y, room[currentroomno].getNumOfRows(), room[currentroomno].getNumOfColumns(), currentroomno, key, gasper, Tkey, totalrooms);
				cor.setx(x);
				cor.sety(y);
				cor.setcurrentRoom(currentroomno);

				coordinate.push(cor);


				room[currentroomno].setroomno(currentroomno);
				room[currentroomno].setr(x);
				room[currentroomno].setc(y);
				roommap.push(room[currentroomno]);

				if (key == 27) {
					cout << "Game ended";
					exit(0);
				}
				if (Tkey == 2) {
					cout << "Treasure is found\n";
					cout << " Iterative: \n";
					coordinate.Print();
					roommap.Print();
					cout << " Recursion: \n";
					recurcoordinate(coordinate, coordinate.sizes(), coordinate.Top());
					recurroom(roommap, roommap.sizes(), roommap.Top());
					exit(0);
				}
				if (gasper == 1) {
					for (int i = 0; i < totalrooms; i++) {
						treasure = room[i].getT();
						if (treasure == 1) {
							save = i;
						}
					}
					currentroomno = save;

				}
				if (currentroomno != prevroomno) {
					prevroomno = currentroomno;
					x = room[currentroomno].getx(), y = room[currentroomno].gety();

					//
					x = rand() % room[currentroomno].getNumOfRows();
					y = rand() % room[currentroomno].getNumOfColumns();
					while (room[currentroomno].getmap(x, y) == 'X' || room[currentroomno].getmap(x, y) == 'D') {
						srand(time(0));
						x = rand() % room[currentroomno].getNumOfRows();
						y = rand() % room[currentroomno].getNumOfColumns();
					}
					//

					room[currentroomno].updatematrix(x, y, room[currentroomno].getNumOfRows(), room[currentroomno].getNumOfColumns(), currentroomno, key, gasper, Tkey, totalrooms);
					cor.setx(x);
					cor.sety(y);
					cor.setcurrentRoom(currentroomno);

					coordinate.push(cor);
					room[currentroomno].setroomno(currentroomno);
					room[currentroomno].setr(x);
					room[currentroomno].setc(y);
					roommap.push(room[currentroomno]);
				}
				break;



			case KEY_ESC:
				cout << "\nGame ended\n";
				exit(0);
				break;

			default:
				break;
			}


		}
	}

	void recurroom(stackList<rooms> obj, int size, rooms top) {
		obj.recur(obj, size, top);
	}
	void recurcoordinate(stackList<coordinates> obj, int size, coordinates top) {
		obj.recur(obj, size, top);
	}
	int number(int m) {
		int ret;
		if (m == 48) { return ret = 0; }
		else if (m == 49) { return ret = 1; }
		else if (m == 50) { return ret = 2; }
		else if (m == 51) { return ret = 3; }
		else if (m == 52) { return ret = 4; }
		else if (m == 53) { return ret = 5; }
		else if (m == 54) { return ret = 6; }
		else if (m == 55) { return ret = 7; }
		else if (m == 56) { return ret = 8; }
		else if (m == 57) { return ret = 9; }

	}
	~hauntedHouse() {
		delete[] room;
	}

};


int main() {
	rooms* room;
	room = new rooms[2];
	int roomcount = 0;
	string reads;
	hauntedHouse listr;

	ifstream fin, finhouse;
	finhouse.open("C:/Users/zaina/Desktop/hauntedhouse.txt");
	if (!finhouse.is_open())
	{
		{
			cout << "Haunted house file" << "accounts.txt" << "cant open";
			exit(0);
		}
	}

	char read;
	int i = 0, count = 0, j = 0, col = 0, row = 0, extra = 0, countHouse = 0;
	while (!finhouse.eof()) {

		getline(finhouse, reads, '\n');
		if (countHouse == 0) {
			int m = stoi(reads);
			listr.setnumOfRooms(m);
		}
		else {
			fin.open(reads);   //open rooms files
			while (!fin.eof())
			{
				fin.get(read);
				if (read != ',' && read != ' ' && read != '\n') {
					if (count == 0) {
						extra = room[roomcount].number(read);
						room[roomcount].setNumOfRows(extra);
						row = room[roomcount].getNumOfRows();
					}
					else if (count == 2) {
						extra = room[roomcount].number(read);
						room[roomcount].setNumOfColumns(extra);
						col = room[roomcount].getNumOfColumns();

						room[roomcount].declaresize(row, col);
					}
					else if (count == 4) {
						extra = room[roomcount].number(read);
						room[roomcount].setx(extra);
					}
					else if (count == 6) {
						extra = room[roomcount].number(read);
						room[roomcount].sety(extra);
					}
					else {
						if (i < row) {
							if (j != (col)) {
								room[roomcount]._map(i, j, read);

								if (read == 'T') {   //Treasure check : increments treasure in room where it is present
									room[roomcount].setT(1);
								}
								j++;
							}
							else {        // increments row
								i++;
								j = 0;
								if (i < row) {
									room[roomcount]._map(i, j, read);

									if (read == 'T') {
										room[roomcount].setT(1);
									}
									j++;
								}
							}
						}
					}
				}
				count++;
			}
			fin.close();
			listr.setRooms(room[roomcount]);//
			roomcount++;//
			count = 0;
			i = 0, j = 0;

		}

		countHouse++;

	}

	finhouse.close();

	listr.Print();
	system("Pause");
	return 0;

}