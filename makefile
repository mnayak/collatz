clean:
	cd collatz; make clean
	@echo

config:
	git config -l

init:
	touch README
	git init
	git add README
	git commit -m 'first commit'
	git remote add origin git@github.com:mnayak/collatz.git
	git push -u origin master

pull:
	@rsync -r -t -u -v --delete             \
    --include "Collatz.c++"                   \

push:
	make clean
	@echo
	git add .travis.yml
	git add collatz
	git add makefile
	git commit -m "another commit"
	git push
	git status

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

test:
	cd collatz; make TestCollatz
	@echo
