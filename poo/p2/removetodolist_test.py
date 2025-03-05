
from src.usecases.createtodolist import CreateTodoList
from src.usecases.removetodolist import RemoveTodoList
from test.usecases.inmemoryuserrepository import InMemoryUserRepository
from test.usecases.inmemorytodolistrepository import InMemoryTodoListRepository
from src.usecases.errors.invalidusererror import InvalidUserError
from src.usecases.errors.invalidremovetodolisterror import RemoveTodoListError
import pytest

def test_successful_todolist_remove():
    user_repo = InMemoryUserRepository()
    todolist_repo = InMemoryTodoListRepository()
    user_email = 'invalid@user.com'
    CreateTodoList(user_repo, todolist_repo)
    usecase = RemoveTodoList(user_repo, todolist_repo)
    with pytest.raises(RemoveTodoListError):
      usecase.perform(user_email)

def test_todolist_remove_error():
    user_repo = InMemoryUserRepository()
    todolist_repo = InMemoryTodoListRepository()
    usecase = RemoveTodoList(user_repo, todolist_repo)
    user_email = 'invalid@user.com'
    with pytest.raises(RemoveTodoListError):
      usecase.perform(user_email)