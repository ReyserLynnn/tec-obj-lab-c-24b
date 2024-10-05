#ifndef NODO_H
#define NODO_H

class Nodo
{
public:
  virtual int evaluar() const = 0;
  virtual void imprimir() const = 0;
  virtual ~Nodo() = default;
};

#endif
