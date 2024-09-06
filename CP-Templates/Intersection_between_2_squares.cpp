struct intersectionBetTwoSqu {//call to intersection function 
    struct point {
        int x, y;
    };

    bool onSegment(point p, point q, point r) {
        if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
                q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
            return true;

        return false;
    }

    int orientation(point p, point q, point r) {
        int val = (q.y - p.y) * (r.x - q.x) -
                  (q.x - p.x) * (r.y - q.y);
        if (val == 0) return 0;
        return (val > 0)? 1: 2;
    }

    bool linesIntersect(point p1, point q1, point p2, point q2) {
        int o1 = orientation(p1, q1, p2);
        int o2 = orientation(p1, q1, q2);
        int o3 = orientation(p2, q2, p1);
        int o4 = orientation(p2, q2, q1);
        if (o1 != o2 && o3 != o4)
            return true;
        if (o1 == 0 && onSegment(p1, p2, q1)) return true;
        if (o2 == 0 && onSegment(p1, q2, q1)) return true;
        if (o3 == 0 && onSegment(p2, p1, q2)) return true;
        if (o4 == 0 && onSegment(p2, q1, q2)) return true;
        return false;
    }

    int isPointInBox(int maxX, int maxY, int minX, int minY, int x, int y) {
        return (x >= minX && x <= maxX && y >= minY && y <= maxY);
    }

    bool intersection(point x[4], point y[4]) {
        bool flag=0;
        for(int i=0; i<4; i++) {
            int maxX=max({y[0].x,y[1].x,y[2].x,y[3].x});
            int minX=min({y[0].x,y[1].x,y[2].x,y[3].x});
            int maxY=max({y[0].y,y[1].y,y[2].y,y[3].y});
            int minY=min({y[0].y,y[1].y,y[2].y,y[3].y});
            flag|=isPointInBox(maxX, maxY, minX, minY, x[i].x, x[i].y);
        }
        for(int i=0; i<4; i++) {
            int maxX=max({x[0].x,x[1].x,x[2].x,x[3].x});
            int minX=min({x[0].x,x[1].x,x[2].x,x[3].x});
            int maxY=max({x[0].y,x[1].y,x[2].y,x[3].y});
            int minY=min({x[0].y,x[1].y,x[2].y,x[3].y});
            flag|=isPointInBox(maxX, maxY, minX, minY, y[i].x, y[i].y);
        }
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                flag|=linesIntersect(x[i],x[(i+1)%4],y[j],y[(j+1)%4]);
            }
        }
        return flag;
    }
};
