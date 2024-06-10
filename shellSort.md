
### Descrição do Shell Sort

```markdown
## Shell Sort

O Shell Sort é um algoritmo de ordenação que generaliza a ordenação por inserção, permitindo a troca de elementos distantes. Ele funciona utilizando uma sequência de intervalos (gaps) decrescentes. A lista é dividida em sublistas baseadas nesses gaps e cada sublista é ordenada usando a ordenação por inserção. 

### Função Shell Sort para a Lista Duplamente Encadeada
A função shellSort irá imprimir o passo a passo do processo de ordenação no terminal, permitindo acompanhar as trocas de valores e os gaps usados durante a ordenação.

```cpp
void shellSort(Node* head)
{
    if (head == nullptr || head->ptrNext == nullptr) {
        return;
    }

    int tamanho = 0;
    Node* temp = head;
    while (temp != nullptr) {
        tamanho++;
        temp = temp->ptrNext;
    }

    cout << "Tamanho da lista: " << tamanho << endl;

    for (int gap = tamanho / 2; gap >= 1; gap /= 2) {
        cout << "Gap atual: " << gap << endl;

        for (int i = gap; i < tamanho; i++) {
            Node* current = head;
            for (int j = 0; j < i; j++) {
                current = current->ptrNext;
            }

            Node* current2 = current;

            cout << "Comparando e possivelmente trocando valores..." << endl;

            for (int j = gap; j > 0 && current2 != nullptr; j--) {
                Node* prev = current2;
                for (int k = 0; k < gap && current2 != nullptr; k++) {
                    current2 = current2->ptrPrev;
                }

                if (current2 != nullptr) {
                    cout << "Comparando " << current2->iPayload << " e " << prev->iPayload << endl;
                    if (current2->iPayload > prev->iPayload) {
                        cout << "Trocando " << current2->iPayload << " e " << prev->iPayload << endl;
                        trocaValor(current2, prev);
                    }
                }
            }
        }
    }
    cout << "Lista ordenada:" << endl;
    displayList(head);
}
