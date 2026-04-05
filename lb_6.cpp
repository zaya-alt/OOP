#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <iomanip>
// #include <string>

using namespace std;

struct Point {
    double x, y;

    Point(double x = 0, double y = 0) {
        this->x = x;
        this->y = y;
    }
};

class Shape {
protected:
    string name;

public:
    Shape(string name = "") {
        this->name = name;
    }

    virtual void printInfo() const = 0;

    virtual ~Shape() {}
};

class TwoDShape : public Shape {
protected:
    vector<Point> points;

public:
    TwoDShape(string name = "") : Shape(name) {}

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

class Circle : public TwoDShape {
private:
    Point center;
    double radius;

public:
    Circle(string name, double x, double y, double radius) : TwoDShape(name) {
        center = Point(x, y);
        this->radius = radius;
        points.push_back(center);
    }

    double area() const override {
        double pi = acos(-1.0);
        return pi * radius * radius;
    }

    double perimeter() const override {
        double pi = acos(-1.0);
        return 2 * pi * radius;
    }

    void printInfo() const override {
        cout << "===== Tsoirog =====" << endl;
        cout << "Ner: " << name << endl;
        cout << "Tuviin koordinat: (" << center.x << ", " << center.y << ")" << endl;
        cout << "Radius: " << radius << endl;
        cout << "Talbai: " << area() << endl;
        cout << "Toirogiiin urt: " << perimeter() << endl;
        cout << endl;
    }
};

class Square : public TwoDShape {
private:
    double side;

public:
    Square(string name, double x, double y, double side) : TwoDShape(name) {
        this->side = side;

        Point topLeft(x, y);
        Point topRight(x + side, y);
        Point bottomRight(x + side, y - side);
        Point bottomLeft(x, y - side);

        points.push_back(topLeft);
        points.push_back(topRight);
        points.push_back(bottomRight);
        points.push_back(bottomLeft);
    }

    double area() const override {
        return side * side;
    }

    double perimeter() const override {
        return 4 * side;
    }

    void printInfo() const override {
        cout << "===== Kvadrat =====" << endl;
        cout << "Ner: " << name << endl;
        cout << "Taliin urt: " << side << endl;
        cout << "Oroinuudiin koordinat:" << endl;
        for (int i = 0; i < points.size(); i++) {
            cout << i + 1 << "-r oroi: (" << points[i].x << ", " << points[i].y << ")" << endl;
        }
        cout << "Talbai: " << area() << endl;
        cout << "Perimetr: " << perimeter() << endl;
        cout << endl;
    }
};

class Triangle : public TwoDShape {
private:
    double side;

public:
    Triangle(string name, double x, double y, double side) : TwoDShape(name) {
        this->side = side;

        double height = sqrt(3.0) / 2.0 * side;

        Point top(x, y);
        Point leftBottom(x - side / 2.0, y - height);
        Point rightBottom(x + side / 2.0, y - height);

        points.push_back(top);
        points.push_back(leftBottom);
        points.push_back(rightBottom);
    }

    double area() const override {
        return (sqrt(3.0) / 4.0) * side * side;
    }

    double perimeter() const override {
        return 3 * side;
    }

    void printInfo() const override {
        cout << "===== Zuv Gurvaljin =====" << endl;
        cout << "Ner: " << name << endl;
        cout << "Taliin urt: " << side << endl;
        cout << "Oroinuudiin koordinat:" << endl;
        for (int i = 0; i < points.size(); i++) {
            cout << i + 1 << "-r oroi: (" << points[i].x << ", " << points[i].y << ")" << endl;
        }
        cout << "Talbai: " << area() << endl;
        cout << "Perimetr: " << perimeter() << endl;
        cout << endl;
    }
};

int main() {
    cout << fixed << setprecision(2);

    Circle c("Tsoirog1", 2, 3, 5);
    Square s("Kvadrat1", 1, 6, 4);
    Triangle t("Gurvaljin1", 0, 8, 6);

    c.printInfo();
    s.printInfo();
    t.printInfo();

    return 0;
}