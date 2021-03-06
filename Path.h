﻿#pragma once

// Этот компонент запускает шарик по определенной траектории, после завершения компонент удаляет сам себя

class Path : public LogicComponent
{
    OBJECT(Path);

public:
    Path(Context* context);
    virtual ~Path();
    static void RegisterObject(Context* context);
    void AddControlPoint(const Vector3& point);
    virtual void Update(float timeStep);
    void SetSpeed(float speed);
    static int GetTotalCount();

private:
    Vector<Vector3> controlPoints_;
    float length_;
    float speed_;
    float traveled_;

    static int totalCount_; // общее число экземпляров объекта, позволяет блокировать игру, когда двигаются шарики
};

