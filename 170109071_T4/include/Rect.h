#ifndef RECT_H
    #define RECT_H

    class Rect{
        public:
            Rect();
            Rect(float x,float y,float w,float h);
            bool Contains(float x,float y);
            float w,h,x,y;
    };

#endif