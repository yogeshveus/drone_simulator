c <- 2 * pi / 3000
d <- 1 / 10
e <- 850

n <- 2000
total_distance <- 3000
t <- seq(0, total_distance, length.out = n)

x <- t + cos(t)
y <- x / d * sin(x / c) + e

write(
  paste("double x[] = {", paste(x, collapse = ", "), "};"),
  file = "data.cpp"
)
write(
  paste("double y[] = {", paste(y, collapse = ", "), "};"),
  file = "data.cpp",
  append = TRUE
)
