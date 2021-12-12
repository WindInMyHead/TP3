#include "List.h"
#include "PhoneMask.h"

List::List() {
    Head = Tail = NULL;
    count = 0;
}

List::~List() {
    DelAll();
}

List& List::operator--() {
    system("cls");
    if (this->IsEmpty()) {
        throw MyException("List is empty");
    }
    else if (count == 1) {
        this->~List();
        cout << "Now this list is empty" << endl;
        return *this;
    }
    else {
        List reserve;
        int cnt = 0;
        Element* temp = Head;
        cout << "Which object do you want to remove?" << endl;
        while (cnt != count) {
            cout << ++cnt << ". " << temp->data->GetName() << endl;
            temp = temp->pNext;
        }
        cout << ">>> ";
        cin >> cnt;
        if (cnt<1 || cnt>count) {
            throw MyException("Id do not exist");
        }
        cnt -= 1;
        temp = Head;

        for (int i = 0; i < cnt - 1; i++) {
            reserve.AddElem(temp);//add to reserv until the deleted-1
            temp = temp->pNext;
        }
        Element* tmp = temp;
        if (this->count == 2) {
            if (cnt == 0) {
                reserve.AddElem(temp->pNext);
            }
            else reserve.AddElem(temp);
            *this = reserve;
            cout << "Complete!" << endl;
            return *this;
        }
        temp->pNext = temp->pNext->pNext;
        reserve.AddElem(temp);
        temp = tmp->pNext;//skip deleted

        for (int i = cnt; i < count - 1; i++) {
            reserve.AddElem(temp);
            temp = temp->pNext;
        }
        reserve.AddElem(temp);

        this->Head = reserve.Head;
        this->Tail = reserve.Tail;
        this->count--;
    }
    cout << "Complete!" << endl;
    return *this;
}

List& List::Del(int cnt) {
    system("cls");
    if (this->IsEmpty()) {
        throw MyException("List is empty");
    }
    if (cnt<0 || cnt>count) {
        throw MyException("Id do not exist");
    }
    List reserve;
    Element* temp = Head;
    for (int i = 0; i < cnt; i++) {
        reserve.AddElem(temp);
        temp = temp->pNext;
    }
    temp = temp->pNext;
    for (int i = cnt + 1; i < count; i++) {
        reserve.AddElem(temp);
        temp = temp->pNext;
    }
    this->Head = reserve.Head;
    count--;
    return *this;
}

void List::Del_head() {
    Element* temp = this->Head;
    Head = this->Head->pNext;
}

void List::DelAll() {
    while (Head != 0) this->Del_head();
    this->count = 0;
}

List& List::operator++() {
    system("cls");
    string name, phone;
    int* bday;
    cout << "===Add object===" << endl;
    //имя
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    //номер телефона
    cout << "Enter phone number: " << endl;
    phone = EnterPhone();
    //дата рождения
    cout << endl << "Enter birth date: " << endl;
    bday = EnterBday();
    Note* memb = new Note(name, phone, bday);
    Element* temp = new Element;
    temp->data = memb;
    temp->pNext = NULL;

    if (this->IsEmpty()) {
        temp->pNext = nullptr;
        Head = Tail = temp;
    }
    else {
        Element* p = Head;
        while (p->pNext != NULL) p = p->pNext;
        p->pNext = temp;
        this->Tail = temp;
    }
    count++;
    system("cls");
    cout << "Complete!" << endl;
    return *this;
}

Element* List::operator[](const int index) {
    if (index < 0 || index >= this->count) throw("Incorrect index");

    if (index == 0) return (*this).Head;
    else if (index == this->count - 1) return (*this).Tail;
    else {
        Element* p = Head;
        for (int i = 0; i < index; i++) {
            p = p->pNext;
        }
        return p;
    }
}

void List::AddElem(Element* elem) {
    if (this->IsEmpty()) {
        Head = Tail = elem;
    }
    else {
        Element* p = Head;
        while (p->pNext != NULL) p = p->pNext;
        this->Tail = elem;
    }

    this->count++;
}

List& List::Edit() {
    system("cls");
    if (this->IsEmpty()) {
        throw MyException("List is empty");
    }
    List main = *this;
    List reserve;
    int cnt = 0;
    Element* temp = new Element;
    temp = Head;
    cout << "Which object do you want to edit?" << endl;
    while (cnt != count) {
        cout << ++cnt << ". " << temp->data->GetName() << endl;
        temp = temp->pNext;
    }
    cout << ">>> ";
    cin >> cnt;
    if (cnt<1 || cnt>count) {
        throw MyException("Id do not exist");
    }
    cnt -= 1;
    temp = main.Head;
    for (int i = 0; i < cnt; i++) {
        reserve.AddElem(temp);
        temp = temp->pNext;
    }
    int v;
    cout << "===EDIT MENU===" << endl;
    cout << "Which parameter do you want to edit?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Phone" << endl;
    cout << "3. bDay" << endl;
    cout << "0. Exit" << endl;
    cin >> v;
    switch (v) {
    case 1:
    {
        string name;
        cout << "Enter new name: ";
        cin.ignore();
        getline(cin, name);
        temp->data->SetName(name);
        cout << "Complete!" << endl;
        break;
    }
    case 2:
    {
        string phone;
        cout << "Enter new phone number:" << endl;
        phone = EnterPhone();
        temp->data->SetPhone(phone);
        cout << endl << "Complete!" << endl;
        break;
    }
    case 3:
    {
        cout << "Enter new birth day:" << endl;
        int* bDay = EnterBday();
        temp->data->SetBday(bDay);
        cout << "Complete!" << endl;
        break;
    }
    default:
    {
        system("cls");
        cout << "Incorrected number" << endl;
        break;
    }
    }

    for (int i = cnt + 1; i < count; i++) {
        reserve.AddElem(temp);
        temp = temp->pNext;
    }
    this->Head = reserve.Head;
    return *this;
}

void List::Print() {
    system("cls");
    Element* temp = this->Head;
    if (this->IsEmpty()) {
        throw MyException("List is empty");
    }
    int cnt = count;
    cout << "===Note===" << endl;
    while (cnt != 0) {
        cout << "Name: " << temp->data->GetName() << endl << "Phone: " << temp->data->GetPhone() << endl << "Birth date: " << temp->data->GetBday()[0]
            << "/" << temp->data->GetBday()[1] << "/" << temp->data->GetBday()[2] << endl;
        // Переходим на следующий элемент
        temp = temp->pNext;
        cnt--;
        cout << "==============" << endl;
    }
}

List& List::RemoveSimilar() {
    system("cls");
    if (this->IsEmpty()) {
        throw MyException("List is empty");
    }
    int flag = 0;
    int cntDel = 0;
    string* names = new string[this->count];
    string* delNames = new string[this->count];
    for (int i = 0; i < this->count; i++) {
        names[i] = (*this)[i]->data->GetName();
        for (int j = i + 1; j < count; j++) {
            names[j] = (*this)[j]->data->GetName();
            if (names[i] == names[j]) {
                flag = 1;
                this->Del(j);
                delNames[cntDel] = names[i];
                cntDel++;
            }
        }
    }
    if (flag == 1) {
        cout << "Complete, ";
        for (int i = 0; i < cntDel; i++) {
            cout << delNames[i] << " ";
        }
        cout << "has been deleted" << endl;
    }
    else {
        cout << "No similar records!" << endl;
    }
    delete[] names, delNames;
    return *this;
}

int List::GetCount() {
    return count;
}
void List::SetCount(int cnt) {
    this->count = cnt;
}

Element* List::GetHead() {
    return Head;
}
void List::SetHead(Element* elem) {
    this->Head = elem;
}

Element* List::GetTail() {
    return Tail;
}
void List::SetTail(Element* elem) {
    this->Tail = elem;
}

void List::SortByBirthday() {
    system("cls");
    if (this->IsEmpty()) throw MyException("List is empty");
    Element* p = this->Head;
    Note* tmp;
    while (p->pNext != NULL) {
        for (int i = 0; i < this->count - 1; i++) {
            for (int j = i + 1; j < this->count; j++) {
                if ((*this)[i]->data->GetBday()[2] > ((*this)[j]->data->GetBday()[2]) ||
                    (((*this)[i]->data->GetBday()[1] > (*this)[j]->data->GetBday()[1]) && ((*this)[i]->data->GetBday()[2] = (*this)[j]->data->GetBday()[2])) ||
                    (((*this)[i]->data->GetBday()[0] > ((*this)[j]->data->GetBday()[0])) && ((*this)[i]->data->GetBday()[1] = (*this)[j]->data->GetBday()[1]) &&
                        ((*this)[i]->data->GetBday()[2] = (*this)[j]->data->GetBday()[2]))) {
                    tmp = (*this)[j]->data;
                    if (i == 0) {
                        (*this)[j]->data = &(*(*this).Head->data);
                        (*this).Head->data = tmp;
                    }
                    else {
                        (*this)[j]->data = &(*(*this)[i - 1]->pNext->data);
                        (*this)[i]->data = tmp;
                    }
                }
            }
            p = p->pNext;
        }
    }
    cout << "Complete!" << endl;
}

void List::SearchByPhone() {
    system("cls");
    if (this->IsEmpty()) throw MyException("List is empty");
    string phone;
    int flag = 0;
    cout << "Enter phone number: " << endl;
    phone = EnterPhone();
    cout << endl;
    Element* p = this->Head;
    while (p->pNext != NULL) {
        if (p->data->GetPhone() == phone) {
            flag = 1;
            cout << "Record with number " << phone << ":" << endl;
            cout << "Name: " << p->data->GetName() << endl << "Phone: " << p->data->GetPhone() << endl << "Birth date: " << p->data->GetBday()[0]
                << "/" << p->data->GetBday()[1] << "/" << p->data->GetBday()[2] << endl;
            break;
        }
        else p = p->pNext;
    }

    if (p->data->GetPhone() == phone && flag == 0){
        flag = 1;
        cout << "Record with number " << phone << ":" << endl;
        cout << "Name: " << p->data->GetName() << endl << "Phone: " << p->data->GetPhone() << endl << "Birth date: " << p->data->GetBday()[0]
            << "/" << p->data->GetBday()[1] << "/" << p->data->GetBday()[2] << endl;
    }

    if (p->data->GetPhone() != phone && flag == 0) throw MyException("There is no record with this phone number");
}

bool List::IsEmpty() {
    return !count;
}