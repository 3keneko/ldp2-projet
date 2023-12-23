#ifndef WINDOW_CONTENTS_H_
#define WINDOW_CONTENTS_H_

class WindowContents {
    public:
        WindowContents() {}
        virtual void draw() = 0;
        virtual ~WindowContents() {}
};

#endif // WINDOW_CONTENTS_H_
