from src.usecases.errors.invalidusererror import InvalidUserError

class RemoveTodoList:
    def __init__(self, user_repo, todolists_repo):
        self.user_repo = user_repo
        self.todolist_repo = todolists_repo

    def perform(self, user_email):
        todolist = self.todolists_repository.find_by_email(user_email)
        if not todolist:
            raise InvalidUserError()
        self.todolists_repo.remove(todolist)
        return self.todolists_repo
