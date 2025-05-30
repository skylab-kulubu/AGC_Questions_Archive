import time

def agcsoru4(n, arr, _, m):
# input: Mermilerin yeri, yuva sayısı, kişi sayısı. output: En son kaçıncı kişi kalır?
    start_time = time.time()

    # n mermi sayısı, arr mermi arrayi, i kontrol edilecek indis, m insan sayısı

    people = set(range(1, int(m + 1)))  # 1'den num_people'a kadar kişiler seti

    i, j = 0, 0

    while len(people) > 1:
        j %= len(people)
        
        it = iter(people)
        for _ in range(j):
            next(it)
        
        i = i % n
        if arr[i] == 0:
            arr[i] = 1
        else:
            arr[i] = 0
            people.remove(next(it))
            j -= 1  # Kişi çıkarıldığında j'yi azalt
        
        i += 1
        j += 1

    end_time = time.time()
    elapsed_time = end_time - start_time
    print(f"Geçen süre: {elapsed_time} saniye")
    print(f"Son kalan kişi: {next(iter(people))}")

#agcsoru4(3, [1, 0, 1], 3319, 4)
