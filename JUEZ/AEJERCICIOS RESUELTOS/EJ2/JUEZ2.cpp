#ifndef TREESET_AVL_H_
#define TREESET_AVL_H_

#include <algorithm>
#include <functional>
#include <stack>
#include <stdexcept>
#include <utility>
#include <iostream>

template <class T, class Comparator = std::less<T>>
class Set
{
protected:
   /*
    Nodo que almacena internamente el elemento (de tipo T),
    punteros al hijo izquierdo y derecho, que pueden ser
    nullptr si el hijo es vac�o, y la altura.
    */
   struct TreeNode;
   using Link = TreeNode *;
   struct TreeNode
   {
      T elem;
      Link left, right;           // Hijo izquierdo y derecho
      int height;                 // Altura del nodo
      int leftSize;               // Tamaño del subárbol izquierdo + 1
      TreeNode(T const &element, Link leftChild = nullptr, Link rightChild = nullptr,
               int h = 1, int size = 1) : elem(element), left(leftChild), right(rightChild), height(h), leftSize(size) {}
   };

   // Puntero a la raíz de la estructura jerárquica de nodos
   Link root;

   // Número de elementos (cardinal del conjunto)
   int numElements;

   // Objeto función que compara elementos (orden total estricto)
   Comparator lessThan;

public:
   // Constructor (conjunto vacío)
   Set(Comparator comp = Comparator()) : root(nullptr), numElements(0), lessThan(comp) {}

   // Constructor por copia
   Set(Set const &other)
   {
      copyTree(other);
   }

   // Operador de asignación
   Set &operator=(Set const &that)
   {
      if (this != &that)
      {
         freeTree(root);
         copyTree(that);
      }
      return *this;
   }

   ~Set()
   {
      freeTree(root);
   };

   bool insert(T const &element)
   {
      bool grown = insertNode(element, root);
      return grown;
   }

   bool empty() const
   {
      return root == nullptr;
   }

   int size() const
   {
      return numElements;
   }

   bool contains(T const &element) const
   {
      return belongsTo(element, root);
   }

   bool erase(T const &element)
   {
      return deleteNode(element, root);
   }

   // Devuelve el k-ésimo elemento más pequeño del conjunto
   T kesimo(int k) const
   {
      int remaining = k;
      return getKthSmallest(remaining, k, root);
   }

protected:
   void incrementLeftSize(T const &element, Link node)
   {
      if (node == nullptr)
      {
      }
      else if (lessThan(element, node->elem))
      {
         node->leftSize = node->leftSize + 1;
         incrementLeftSize(element, node->left);
      }
      else if (lessThan(node->elem, element))
      {
         incrementLeftSize(element, node->right);
      }
   }

   // Busca el k-ésimo elemento más pequeño usando el tamaño del subárbol izquierdo
   T getKthSmallest(int &remaining, int k, Link node) const
   {
      if (node->left == nullptr && node->right == nullptr)
      {
         int difference = remaining - node->leftSize;
         if (difference == 0)
            return node->elem;
         else
            throw std::runtime_error("??");
      }
      else
      {
         int difference = remaining - node->leftSize;
         if (difference == 0)
            return node->elem;
         else
         {
            if (difference < 0)
            {
               if (node->left == nullptr)
                  throw std::runtime_error("??");
               return getKthSmallest(remaining, k, node->left);
            }
            else
            {
               remaining -= node->leftSize;
               if (node->right == nullptr)
                  throw std::runtime_error("??");
               return getKthSmallest(remaining, k, node->right);
            }
         }
      }
   }

   // Copia un árbol completo
   void copyTree(Set const &other)
   {
      root = copyTree(other.root);
      numElements = other.numElements;
      lessThan = other.lessThan;
   }

   static Link copyTree(Link node)
   {
      if (node == nullptr)
         return nullptr;
      else
         return new TreeNode(node->elem, copyTree(node->left), copyTree(node->right), node->height);
   }

   // Libera memoria de todos los nodos del árbol
   static void freeTree(Link node)
   {
      if (node != nullptr)
      {
         freeTree(node->left);
         freeTree(node->right);
         delete node;
      }
   }

   // Verifica si un elemento pertenece al árbol
   bool belongsTo(T const &element, Link node) const
   {
      if (node == nullptr)
      {
         return false;
      }
      else if (lessThan(element, node->elem))
      {
         return belongsTo(element, node->left);
      }
      else if (lessThan(node->elem, element))
      {
         return belongsTo(element, node->right);
      }
      else
      { // element == node->elem
         return true;
      }
   }

   // Inserta un elemento en el árbol AVL
   bool insertNode(T const &element, Link &node)
   {
      bool grown;
      if (node == nullptr)
      { // Se inserta el nuevo elemento
         node = new TreeNode(element);
         ++numElements;
         grown = true;
      }
      else if (lessThan(element, node->elem))
      {
         grown = insertNode(element, node->left);
         if (grown)
         {
            node->leftSize++;
            rebalanceRight(node);
         }
      }
      else if (lessThan(node->elem, element))
      {
         grown = insertNode(element, node->right);
         if (grown)
         {
            rebalanceLeft(node);
         }
      }
      else // El elemento ya está en el árbol
         grown = false;
      return grown;
   }

   // Devuelve la altura de un nodo
   int getHeight(Link node)
   {
      if (node == nullptr)
         return 0;
      else
         return node->height;
   }

   // Rotación simple a la derecha
   void rotateRight(Link &parent)
   {
      Link child = parent->left;
      parent->left = child->right;
      child->right = parent;
      parent->height = std::max(getHeight(parent->left), getHeight(parent->right)) + 1;
      child->height = std::max(getHeight(child->left), getHeight(child->right)) + 1;
      child->leftSize = calculateNumNodes(child->left) + 1;
      parent->leftSize = calculateNumNodes(parent->left) + 1;
      parent = child;
   }

   // Calcula el número total de nodos en un subárbol
   int calculateNumNodes(Link &node)
   {
      if (node == nullptr)
         return 0;
      else
      {
         return 1 + calculateNumNodes(node->left) + calculateNumNodes(node->right);
      }
   }

   // Rotación simple a la izquierda
   void rotateLeft(Link &parent)
   {
      Link child = parent->right;
      parent->right = child->left;
      child->left = parent;
      parent->height = std::max(getHeight(parent->left), getHeight(parent->right)) + 1;
      child->height = std::max(getHeight(child->left), getHeight(child->right)) + 1;
      parent->leftSize = calculateNumNodes(parent->left) + 1;
      child->leftSize = calculateNumNodes(child->left) + 1;
      parent = child;
   }

   // Rotación doble izquierda-derecha
   void rotateLeftRight(Link &node)
   {
      rotateLeft(node->left);
      rotateRight(node);
   }

   // Rotación doble derecha-izquierda
   void rotateRightLeft(Link &node)
   {
      rotateRight(node->right);
      rotateLeft(node);
   }

   // Reequilibra cuando el subárbol derecho está más alto
   void rebalanceLeft(Link &node)
   {
      if (getHeight(node->right) - getHeight(node->left) > 1)
      {
         if (getHeight(node->right->left) > getHeight(node->right->right))
            rotateRightLeft(node);
         else
            rotateLeft(node);
      }
      else
         node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
   }

   // Reequilibra cuando el subárbol izquierdo está más alto
   void rebalanceRight(Link &node)
   {
      if (getHeight(node->left) - getHeight(node->right) > 1)
      {
         if (getHeight(node->left->right) > getHeight(node->left->left))
            rotateLeftRight(node);
         else
            rotateRight(node);
      }
      else
         node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
   }

   // Devuelve y borra el mínimo del árbol con raíz en node
   T deleteMin(Link &node)
   {
      if (node->left == nullptr)
      {
         T minValue = node->elem;
         node = node->right;
         --numElements;
         return minValue;
      }
      else
      {
         T minValue = deleteMin(node->left);
         rebalanceLeft(node);
         return minValue;
      }
   }

   // Elimina un elemento del árbol AVL
   bool deleteNode(T const &element, Link &node)
   {
      bool shrunk = false;
      if (node != nullptr)
      {
         if (lessThan(element, node->elem))
         {
            shrunk = deleteNode(element, node->left);
            if (shrunk)
               rebalanceLeft(node);
         }
         else if (lessThan(node->elem, element))
         {
            shrunk = deleteNode(element, node->right);
            if (shrunk)
               rebalanceRight(node);
         }
         else
         { // element == node->elem
            if (node->left == nullptr || node->right == nullptr)
            {
               Link temp = node;
               node = (node->left == nullptr) ? node->right : node->left;
               --numElements;
               delete temp;
            }
            else
            { // Tiene dos hijos
               T minValue = deleteMin(node->right);
               node->elem = minValue;
               rebalanceRight(node);
            }
            shrunk = true;
         }
      }
      return shrunk;
   }

public:
   // Iterador que recorre los elementos del conjunto de menor a mayor
   class const_iterator
   {
   public:
      T const &operator*() const
      {
         if (current == nullptr)
            throw std::out_of_range("No hay elemento a consultar");
         return current->elem;
      }

      T const *operator->() const
      {
         return &operator*();
      }

      const_iterator &operator++()
      { // ++ prefijo
         advance();
         return *this;
      }

      bool operator==(const_iterator const &that) const
      {
         return current == that.current;
      }

      bool operator!=(const_iterator const &that) const
      {
         return !(this->operator==(that));
      }

   protected:
      friend class Set;
      Link current;
      std::stack<Link> ancestors;  // Ancestros no visitados

      // Construye el iterador al primero
      const_iterator(Link rootNode) { current = findFirst(rootNode); }

      // Construye el iterador al final
      const_iterator() : current(nullptr) {}

      // Encuentra el nodo más a la izquierda (mínimo)
      Link findFirst(Link node)
      {
         if (node == nullptr)
         {
            return nullptr;
         }
         else
         { // Buscamos el nodo más a la izquierda
            while (node->left != nullptr)
            {
               ancestors.push(node);
               node = node->left;
            }
            return node;
         }
      }

      // Avanza al siguiente elemento en orden
      void advance()
      {
         if (current == nullptr)
         {
            throw std::out_of_range("El iterador no puede avanzar");
         }
         else if (current->right != nullptr)
         { // Primero del hijo derecho
            current = findFirst(current->right);
         }
         else if (ancestors.empty())
         { // Hemos llegado al final
            current = nullptr;
         }
         else
         { // Retrocedemos al ancestro
            current = ancestors.top();
            ancestors.pop();
         }
      }
   };

   const_iterator begin() const
   {
      return const_iterator(root);
   }

   const_iterator end() const
   {
      return const_iterator();
   }
};

#endif

// Resuelve un caso de prueba
bool solveCase()
{
   int numElements;
   std::cin >> numElements;
   if (numElements == 0)
      return false;
   
   // Leer elementos e insertarlos en el conjunto
   Set<int> mySet;
   for (int i = 0; i < numElements; i++)
   {
      int element;
      std::cin >> element;
      mySet.insert(element);
   }
   
   // Procesar consultas del k-ésimo elemento
   int numQueries;
   std::cin >> numQueries;
   for (int j = 0; j < numQueries; j++)
   {
      int k;
      std::cin >> k;
      try
      {
         std::cout << mySet.kesimo(k) << '\n';
      }
      catch (const std::runtime_error &error)
      {
         std::cout << error.what() << '\n';
      }
   }
   std::cout << "---\n";
   return true;
}

int main()
{
   while (solveCase())
   {
   }
   return 0;
}