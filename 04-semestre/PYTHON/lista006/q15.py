tasks = []

while True:
	comando = input("Digite um comando (ADD, DONE, LIST, EXIT): ").strip().upper()
	if not comando:
		continue

	if comando == "ADD":
		titulo = input("Titulo da tarefa: ").strip()
		prioridade_texto = input("Prioridade (1-5): ").strip()
		if not prioridade_texto.isdigit():
			print("Prioridade invalida. Informe um numero de 1 a 5.")
			continue

		prioridade = int(prioridade_texto)
		if prioridade < 1 or prioridade > 5:
			print("Prioridade invalida. Informe um numero de 1 a 5.")
			continue

		tasks.append({"titulo": titulo, "prioridade": prioridade, "status": "aberta"})
		print("Tarefa adicionada.")

	elif comando == "DONE":
		titulo = input("Titulo da tarefa concluida: ").strip()
		for tarefa in tasks:
			if tarefa["titulo"].lower() == titulo.lower():
				tarefa["status"] = "concluida"
				print("Tarefa marcada como concluida.")
				break
		else:
			print("Tarefa nao encontrada.")

	elif comando == "LIST":
		filtro = input("Filtrar por status (aberta/concluida) ou pressione Enter: ").strip().lower()
		if filtro not in ("", "aberta", "concluida"):
			print("Filtro invalido.")
			continue

		tarefas_para_mostrar = tasks
		if filtro:
			tarefas_para_mostrar = [tarefa for tarefa in tasks if tarefa["status"] == filtro]

		if not tarefas_para_mostrar:
			print("Nenhuma tarefa para listar.")
			continue

		for tarefa in sorted(tarefas_para_mostrar, key=lambda t: t["prioridade"]):
			print(
				f"Titulo: {tarefa['titulo']} | Prioridade: {tarefa['prioridade']} | Status: {tarefa['status']}"
			)

	elif comando == "EXIT":
		print("Encerrando agenda de tarefas.")
		break

	else:
		print("Comando invalido.")
